#ifndef GUI_H
#define GUI_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <cmath>
#include <iostream>
#include <string>
#include "Inventory.h"
#include "Customer.h"
#include "PlantIterator.h"
#include "Plant.h"
#include <algorithm>
#include <fstream>
#include <map>
#include <vector>
#include <random>
#include "order.h"

using namespace std;
using namespace sf;

// Customer structure to track individual customers
struct CustomerDetails {
    Sprite sprite;
    Sprite speechBubble;
    Vector2f targetPos;
    Vector2f currentPos;
    float alpha;
    bool isMoving;
    bool hasArrived;
    Clock animationClock;
    int customerType;
    
    CustomerDetails() : alpha(0.f), isMoving(true), hasArrived(false), customerType(1) {}
};

class gui : public RenderWindow{
    private: 
    int width, height;
    Font font;
    Inventory* inventory;
    std::map<std::string, Texture> textureCache;
    float scrollOffset;
    bool returningToGreenhouse = false;
    Vector2f careStaffStartPos;
    
    // Customer management
    std::vector<CustomerDetails> activeCustomers;
    Clock customerSpawnClock;
    float customerSpawnInterval;
    int maxCustomers;
    vector<Zone*>* ExistingZones;
    std::mt19937 rng;

    Texture* careStaffTexture = nullptr;

    // Zone sprites
    Sprite* FlowerBed = nullptr;
    Sprite* Desert = nullptr;
    Sprite* HerbsAndAromatics = nullptr;
    Sprite* TreeAndShrub = nullptr; 

    // Care staff movement
    Vector2f greenhousePosition;
    Sprite careStaffSprite;
    bool isMovingCareStaff = false;
    Vector2f careStaffTarget;
    float careStaffSpeed = 200.f; // pixels per second

    // Customer staff movement
    Sprite customerStaffSprite;
    Vector2f customerStaffOriginalPos;
    bool isMovingCustomerStaff = false;
    Vector2f customerStaffTarget;
    float customerStaffSpeed = 200.f; // pixels per second

    // Greenhouse assets
    Texture* greenhouseTexture = nullptr;
    Sprite* greenhouseSprite = nullptr;

    //vector of customers
    vector<Customer*> custs;
    CustomerStaff* c;


    
    public:
    gui(VideoMode mode, const string& title, Uint32 style = Style::Default, Inventory* inv = nullptr, vector<Zone*>* zones = nullptr, vector<Customer*>* customers = nullptr, CustomerStaff* custStaff =nullptr) 
        : RenderWindow(mode, title, style), inventory(inv), scrollOffset(0.f), ExistingZones(zones),custs(*customers) ,c(custStaff),
          customerSpawnInterval(5.f), maxCustomers(3), rng(std::random_device{}()){
        width = mode.width;
        height = mode.height;
        this->setFramerateLimit(60);
        this->setSize(Vector2u(mode.width, mode.height));
        this->setPosition(Vector2i((VideoMode::getDesktopMode().width - width) / 2, 
                                   (VideoMode::getDesktopMode().height - height) / 2));

        if (!font.loadFromFile("ARIAL.TTF")) {
            cout << "Failed to load font ARIAL.TTF" << endl;
        } else {
            cout << "Font loaded successfully!" << endl;
        }

        if (!this->isOpen()) {
            cout << "Failed to create window!" << endl;
        } else {
            cout << "Window created successfully!" << endl;
        }
    }
   
    ~gui() {
        if (this->isOpen()) this->close();
        cout << "Window closed." << endl;
    }

    void displayWindow() {
        const float scrollStep = 30.f;
        sf::Clock deltaClock;

        while (this->isOpen()) {
            int i = 0;
            float dt = deltaClock.restart().asSeconds();

            Event event;
            while (this->pollEvent(event)) {
                if (event.type == Event::Closed) {
                    this->close();
                } else if (event.type == Event::MouseWheelScrolled) {
                    if (event.mouseWheelScroll.wheel == Mouse::VerticalWheel) {
                        scrollOffset -= event.mouseWheelScroll.delta * scrollStep;
                        if (scrollOffset < 0.f) scrollOffset = 0.f;
                    }
                }
                else if (event.type == Event::KeyPressed) { 
                    if (event.key.code == Keyboard::I) {
                        this->moveCareStaffToInventory();
                    }
                    else if (event.key.code == Keyboard::G) {
                        this->moveCareStaffToGreenhouse();
                    }
                    else if (event.key.code == Keyboard::C) {
                        this->moveCustomerStaffToInventory();
                    }
                    else if (event.key.code == Keyboard::B) {
                        this->moveCustomerStaffBack();
                    }
                }
            }

            // Update care staff position if moving
            if (isMovingCareStaff) {
                Vector2f currentPos = careStaffSprite.getPosition();
                Vector2f direction = careStaffTarget - currentPos;
                float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);

                if (distance > 2.f) {
                    direction /= distance;
                    careStaffSprite.move(direction * careStaffSpeed * dt);
                } else {
                    careStaffSprite.setPosition(careStaffTarget);
                    isMovingCareStaff = false;
                    std::cout << "Care staff reached target!" << std::endl;
                }
            }

            // Update customer staff position if moving
            if (isMovingCustomerStaff) {
                Vector2f currentPos = customerStaffSprite.getPosition();
                Vector2f direction = customerStaffTarget - currentPos;
                float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);

                if (distance > 2.f) {
                    direction /= distance;
                    customerStaffSprite.move(direction * customerStaffSpeed * dt);
                } else {
                    customerStaffSprite.setPosition(customerStaffTarget);
                    isMovingCustomerStaff = false;
                    // std::cout << "Customer staff reached target!" << std::endl;
                }
            }

        
            this->clear(Color::White);
            this->displayStore();
            this->displayInventory();
            this->displaySeedsinZone();
            this->displayCareStaff();
            //for 15 seconds execute customer actions
            this->executeCustomerCommands();

            this->display();

        }
    }

void executeCustomerCommands(){
    static Clock executionClock;
    static bool hasStarted = false;
    static int currentAction = 0;
    static bool actionInProgress = false;
    static Clock actionClock;
    
    if (!hasStarted) {
        executionClock.restart();
        hasStarted = true;
        currentAction = 0;
        actionInProgress = false;
    }
    
    float elapsed = executionClock.getElapsedTime().asSeconds();
    
    // Execute for 15 seconds
    if (elapsed > 15.f) {
        hasStarted = false;
        currentAction = 0;
        actionInProgress = false;
        activeCustomers.clear();
        return;
    }
    
    // Get customer staff position (he stays here)
    Vector2f staffPos = customerStaffSprite.getPosition();
    FloatRect staffBounds = customerStaffSprite.getGlobalBounds();
    
    // Position customers to the right of the staff
    Vector2f customer1Pos = Vector2f(staffBounds.left + staffBounds.width + 20.f, staffBounds.top + 50.f);
    Vector2f customer2Pos = Vector2f(staffBounds.left + staffBounds.width + 130.f, staffBounds.top + 50.f);
    Vector2f customer3Pos = Vector2f(staffBounds.left + staffBounds.width + 240.f, staffBounds.top + 50.f);
    
    // Customer 1: Buy plant (rose) - starts at 0s
    if (currentAction == 0 && elapsed >= 0.f) {
        if (!actionInProgress) {

            // Spawn customer 1
            spawnCustomer(1, customer1Pos, "Potted rose x1");
            
            // Execute buy command only if customer exists
            if (!inventory->getInstance()->isRosesEmpty()&&!custs.empty() && custs.size() > 0 && custs[0] != nullptr && c != nullptr) {
                try {
                    Order o;
                    o.base = "Potted";
                    o.flowerName = "rose";
                    o.num = 1;
                    custs[0]->buyPlant(c, &o);
                } catch (...) {
                    std::cout << "Error in buyPlant for customer 1" << std::endl;
                }
            }
            else{
                return;
            }
            // custStaff->
            actionInProgress = true;
            actionClock.restart();
        }
        
        // Move to next action after 4 seconds
        if (actionClock.getElapsedTime().asSeconds() > 4.f) {
            currentAction = 1;
            actionInProgress = false;
        }
    }
    
    // Customer 2: Request help - starts at 5s
    if (currentAction == 1 && elapsed >= 5.f) {
        if (!actionInProgress) {
            // Spawn customer 2 (customer staff does NOT move)
            spawnCustomer(2, customer2Pos, "I need something\nromantic");
            
            // Execute help request only if customer exists
            if (custs.size() > 1 && custs[1] != nullptr && c != nullptr) {
                try {
                    std::string question = "i need something romantic";
                    custs[1]->requestHelp(c, question);
                } catch (...) {
                    std::cout << "Error in requestHelp for customer 2" << std::endl;
                }
            }
            
            actionInProgress = true;
            actionClock.restart();
        }
        
        // Move to next action after 4 seconds
        if (actionClock.getElapsedTime().asSeconds() > 4.f) {
            currentAction = 2;
            actionInProgress = false;
        }
    }
    
    
    // Update and display all active customers
    try {
        updateAndDisplayCustomers();
    } catch (...) {
        std::cout << "Error in updateAndDisplayCustomers" << std::endl;
    }
}

void executeCareCommands(){
    for(auto z : *ExistingZones){
        for(auto zip : z->getChildren()){
            Plant* p = (Plant*)zip;
            p->dailyTick();
            cout << "Plant: "<< p->getName() <<"Age days: "<<p->getAgeDays() << "Height: " << p->getHeight() << endl;
        }
    }

}
// Helper method to spawn a customer with speech bubble
void spawnCustomer(int customerNum, Vector2f position, const std::string& message) {
    try {
        CustomerDetails customer;
        
        // Load customer sprite
        std::string customerPath = "Customers/customer" + std::to_string(customerNum) + ".png";
        Texture* customerTex = loadTexture(customerPath);
        if (customerTex) {
            customer.sprite.setTexture(*customerTex, true);
            Vector2u texSize = customerTex->getSize();
            if (texSize.x > 0 && texSize.y > 0) {
                float scale = 100.f / static_cast<float>(std::max(texSize.x, texSize.y));
                customer.sprite.setScale(scale, scale);
            } else {
                std::cout << "Invalid texture size for customer " << customerNum << std::endl;
                return;
            }
        } else {
            std::cout << "Failed to load customer texture: " << customerPath << std::endl;
            return;
        }
        
        // Load speech bubble
        Texture* bubbleTex = loadTexture("Customers/s_bubble.png");
        if (bubbleTex) {
            customer.speechBubble.setTexture(*bubbleTex, true);
            Vector2u texSize = bubbleTex->getSize();
            if (texSize.x > 0 && texSize.y > 0) {
                float scale = 150.f / static_cast<float>(std::max(texSize.x, texSize.y));
                customer.speechBubble.setScale(scale, scale);
            }
        } else {
            std::cout << "Failed to load speech bubble texture" << std::endl;
        }
        
        customer.targetPos = position;
        // Start from right side of screen
        customer.currentPos = Vector2f(static_cast<float>(this->getSize().x) + 100.f, position.y);
        customer.sprite.setPosition(customer.currentPos);
        customer.alpha = 0.f;
        customer.isMoving = true;
        customer.hasArrived = false;
        customer.customerType = customerNum;
        
        activeCustomers.push_back(customer);
        
        std::cout << "Customer " << customerNum << " spawned with message: " << message << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception in spawnCustomer: " << e.what() << std::endl;
    } catch (...) {
        std::cout << "Unknown exception in spawnCustomer" << std::endl;
    }
}

// Helper method to update and display customers
void updateAndDisplayCustomers() {
    if (activeCustomers.empty()) {
        return;
    }
    
    // Define messages for each customer type
    static std::map<int, std::string> customerMessages = {
        {1, "Potted rose x1"},
        {2, "I need something\nromantic"},
        // {3, "Wrapped Tulip x2\n+ Ribbon"}
    };
    
    try {
        const float moveSpeed = 200.f;
        const float fadeSpeed = 3.f;
        float dt = 1.f / 60.f;
        
        for (size_t i = 0; i < activeCustomers.size(); ++i) {
            CustomerDetails& customer = activeCustomers[i];
            
            // Check if sprite has valid texture before proceeding
            if (customer.sprite.getTexture() == nullptr) {
                continue;
            }
            
            // Fade in
            if (customer.alpha < 255.f) {
                customer.alpha += fadeSpeed * 255.f * dt;
                if (customer.alpha > 255.f) customer.alpha = 255.f;
            }
            
            // Move to target position (walk from right to customer staff)
            if (customer.isMoving) {
                Vector2f direction = customer.targetPos - customer.currentPos;
                float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);
                
                if (distance > 2.f) {
                    direction /= distance;
                    customer.currentPos += direction * moveSpeed * dt;
                    customer.sprite.setPosition(customer.currentPos);
                } else {
                    customer.currentPos = customer.targetPos;
                    customer.sprite.setPosition(customer.currentPos);
                    customer.isMoving = false;
                    customer.hasArrived = true;
                }
            }
            
            // Set transparency
            try {
                Color spriteColor = customer.sprite.getColor();
                spriteColor.a = static_cast<Uint8>(customer.alpha);
                customer.sprite.setColor(spriteColor);
                
                // Draw customer
                this->draw(customer.sprite);
            } catch (...) {
                std::cout << "Error drawing customer sprite " << i << std::endl;
                continue;
            }
            
            // Draw speech bubble above customer if arrived
            if (customer.hasArrived && customer.speechBubble.getTexture() != nullptr) {
                try {
                    FloatRect bounds = customer.sprite.getGlobalBounds();
                    
                    // Position speech bubble above customer
                    float bubbleX = bounds.left + bounds.width / 2.f - 75.f;
                    float bubbleY = bounds.top - 100.f;
                    customer.speechBubble.setPosition(bubbleX, bubbleY);
                    
                    Color bubbleColor = customer.speechBubble.getColor();
                    bubbleColor.a = static_cast<Uint8>(customer.alpha);
                    customer.speechBubble.setColor(bubbleColor);
                    
                    this->draw(customer.speechBubble);
                    
                    // Draw text inside speech bubble
                    std::string message = customerMessages[customer.customerType];
                    Text messageText(message, font, 12);
                    messageText.setFillColor(Color(50, 50, 50, static_cast<Uint8>(customer.alpha)));
                    messageText.setStyle(Text::Bold);
                    
                    // Center text in bubble
                    FloatRect textBounds = messageText.getLocalBounds();
                    FloatRect bubbleBounds = customer.speechBubble.getGlobalBounds();
                    
                    float textX = bubbleX + (bubbleBounds.width - textBounds.width) / 2.f - textBounds.left;
                    float textY = bubbleY + (bubbleBounds.height - textBounds.height) / 2.f - textBounds.top - 5.f;
                    
                    messageText.setPosition(textX, textY);
                    this->draw(messageText);
                    
                } catch (...) {
                    std::cout << "Error drawing speech bubble " << i << std::endl;
                }
            }
        }
    } catch (const std::exception& e) {
        std::cout << "Exception in updateAndDisplayCustomers: " << e.what() << std::endl;
    } catch (...) {
        std::cout << "Unknown exception in updateAndDisplayCustomers" << std::endl;
    }
}

Texture* loadTexture(const string& filepath) {
        auto it = textureCache.find(filepath);
        if (it != textureCache.end()) {
            return &(it->second);
        }
        
        Texture& texture = textureCache[filepath];
        if (!texture.loadFromFile(filepath)) {
            cout << "Failed to load texture from " << filepath << endl;
            textureCache.erase(filepath);
            return nullptr;
        }
        
        return &texture;
    }

    void displaySeedsinZone() {
        if (!ExistingZones || ExistingZones->empty()) return;
        if (!greenhouseSprite) return;

        const float seedSize = 66.f;

        FloatRect ghBounds = greenhouseSprite->getGlobalBounds();

        float topShelfY = ghBounds.top + ghBounds.height * 0.80f;
        float midShelfY = ghBounds.top + ghBounds.height * 0.59f;
        float botShelfY = ghBounds.top + ghBounds.height * 0.80f;

        float leftX = ghBounds.left + ghBounds.width * 0.40f;
        float rightX = ghBounds.left + ghBounds.width * 0.68f;

        // Preload seed sprites
        for (auto z : *ExistingZones) {
            if (!z) continue;

            std::string category = z->getZoneCategory();
            bool hasPlants = !z->getChildren().empty();
            std::string texPath;

            if (category == "Flower" && !FlowerBed)
                texPath = hasPlants ? "Seeds/Flower.png" : "Seeds/warn.png";
            else if (category == "Cactus&Succulent" && !Desert)
                texPath = hasPlants ? "Seeds/Cactus&Succulents.png" : "Seeds/warn.png";
            else if (category == "Herb&Aromatic" && !HerbsAndAromatics)
                texPath = hasPlants ? "Seeds/Herb&Aromatic.png" : "Seeds/warn.png";
            else if (category == "Tree&Shrub" && !TreeAndShrub)
                texPath = hasPlants ? "Seeds/Trees&Shrubs.png" : "Seeds/warn.png";
            else
                continue;

            Texture* tex = loadTexture(texPath);
            if (tex) {
                Sprite* s = new Sprite(*tex);
                if (category == "Flower") FlowerBed = s;
                else if (category == "Cactus&Succulent") Desert = s;
                else if (category == "Herb&Aromatic") HerbsAndAromatics = s;
                else if (category == "Tree&Shrub") TreeAndShrub = s;
            }
        }

        std::map<std::string, Sprite*> seeds = {
            {"Flower", FlowerBed},
            {"Cactus&Succulent", Desert},
            {"Herb&Aromatic", HerbsAndAromatics},
            {"Tree&Shrub", TreeAndShrub}
        };

        struct Pos { float x, y; };
        std::map<std::string, Pos> posMap = {
            {"Flower", {leftX, topShelfY}},
            {"Cactus&Succulent", {rightX, topShelfY}},
            {"Herb&Aromatic", {leftX, midShelfY}},
            {"Tree&Shrub", {rightX, midShelfY}}
        };

        for (auto& [cat, s] : seeds) {
            if (!s || posMap.find(cat) == posMap.end()) continue;
            auto [x, y] = posMap[cat];

            Vector2u texSize = s->getTexture()->getSize();
            float scale = seedSize / static_cast<float>(std::max(texSize.x, texSize.y));
            s->setScale(scale, scale);

            float spriteW = texSize.x * scale;
            float spriteH = texSize.y * scale;

            s->setPosition(x - spriteW + 5.f / 2.f, y - spriteH);
            this->draw(*s);
        }
    }

    void displayInventory() {
        if (!inventory) {
            std::cout << "Missing inventory" << std::endl;
            return;
        }

        const float boxWidth = 240.f;
        const float boxHeight = 450.f;
        const float margin = 15.f;
        const float padding = 10.f;
        
        const float cellWidth = (boxWidth - 2 * padding - 5.f) / 2.f;
        const float cellHeight = 70.f;
        const float iconSize = 35.f;

        const float boxX = this->getSize().x - boxWidth - margin;
        const float boxY = margin;

        RectangleShape box(Vector2f(boxWidth, boxHeight));
        box.setFillColor(Color(245, 245, 245, 240));
        box.setOutlineColor(Color::Black);
        box.setOutlineThickness(2.f);
        box.setPosition(boxX, boxY);
        this->draw(box);

        Texture* inventoryLogo = loadTexture("Inventory/warehouse.png");
        if (inventoryLogo) {
            Sprite sprite(*inventoryLogo);
            Vector2u texSize = inventoryLogo->getSize();

            float desiredSize = 35.f;
            float scale = desiredSize / std::max(texSize.x, texSize.y);
            sprite.setScale(scale, scale);

            float iconX = boxX - desiredSize - 10.f;
            float iconY = boxY + 10.f;
            sprite.setPosition(iconX, iconY);

            this->draw(sprite);
        }

        const std::vector<std::string> plantsAvailable = {
            "Roses", "Daisies", "Tulips", "Succulents", "Cactuses",
            "Basils", "Mints", "Parsleys", "Corianders", "Lavenders",
            "Rosemary", "LemonBalms", "Hibiscus", "Hydrangea",
            "Boxwood", "Oak", "Baobab", "Seeds"
        };

        std::map<std::string, int> plantCounts;
        int totalPlants = 0;
        for (const auto& plantType : plantsAvailable) {
            PlantIterator* it = inventory->createIterator(plantType);
            if (it) {
                int count = it->count();
                totalPlants += count;
                if (count > 0) plantCounts[plantType] = count;
                delete it;
            }
        }

        const int columns = 2;
        const int totalRows = (plantCounts.size() + columns - 1) / columns;
        const float contentHeight = totalRows * cellHeight;
        const float viewableHeight = boxHeight - 70.f;
        const float maxScroll = std::max(0.f, contentHeight - viewableHeight);
        if (scrollOffset > maxScroll) scrollOffset = maxScroll;

        float startX = boxX + padding;
        float startY = boxY + 45.f - scrollOffset;
        int index = 0;

        for (const auto& [plantName, count] : plantCounts) {
            int col = index % columns;
            int row = index / columns;

            float cellX = startX + col * cellWidth;
            float cellY = startY + row * cellHeight;

            if (cellY + cellHeight < boxY + 40.f || cellY > boxY + 40.f + viewableHeight) {
                index++;
                continue;
            }

            std::string imagePath = "Plants/" + plantName + ".png";
            Texture* texture = loadTexture(imagePath);
            if (texture) {
                Sprite sprite(*texture);
                Vector2u texSize = texture->getSize();
                float scale = iconSize / std::max(texSize.x, texSize.y);
                sprite.setScale(scale, scale);
                sprite.setPosition(cellX + 3.f, cellY + 5.f);
                this->draw(sprite);
            }

            string displayName = plantName;
            if (displayName.length() > 10) {
                displayName = displayName.substr(0, 8) + "..";
            }
            
            Text nameText(displayName, font, 11);
            nameText.setFillColor(Color::Black);
            nameText.setPosition(cellX + 43.f, cellY + 10.f);
            this->draw(nameText);

            Text qtyText("x" + std::to_string(count), font, 11);
            qtyText.setFillColor(Color(80, 80, 80));
            qtyText.setPosition(cellX + 43.f, cellY + 28.f);
            this->draw(qtyText);

            index++;
        }

        RectangleShape bottomBar(Vector2f(boxWidth, 35.f));
        bottomBar.setFillColor(Color(235, 235, 235));
        bottomBar.setPosition(boxX, boxY + boxHeight - 35.f);
        this->draw(bottomBar);

        Text totalText("Total: " + std::to_string(totalPlants), font, 16);
        totalText.setFillColor(Color::Black);
        totalText.setStyle(Text::Bold);
        totalText.setPosition(boxX + 10.f, boxY + boxHeight - 28.f);
        this->draw(totalText);
    }

    void displayShelves(){
        Texture* shelf = loadTexture("Store/Shelf.png");
        if (shelf) {
            const int rows = 3;
            const int cols = 3;
            const float shelfWidth = 250.f;
            const float shelfHeight = 100.f;
            const float startX = 30.f;
            const float startY = 20.f;
            const float xSpacing = 1.f;
            const float yOverlap = 25.f;

            for (int row = 0; row < rows; row++) {
                for (int col = 0; col < cols; col++) {
                    Sprite sprite(*shelf);
                    Vector2u texSize = shelf->getSize();

                    float scale = (shelfHeight / texSize.y) * 1.7f;
                    sprite.setScale(scale, scale);

                    float xPos = startX + (col * (shelfWidth - xSpacing * 150));
                    float yPos = startY + (row * (shelfHeight - yOverlap));
                    sprite.setPosition(xPos, yPos);

                    this->draw(sprite);
                }
            }

            Texture* ghTex = loadTexture("Store/Greenhouse.png");
            if (ghTex) {
                this->greenhouseTexture = ghTex;

                if (!this->greenhouseSprite) this->greenhouseSprite = new Sprite(*ghTex);
                else this->greenhouseSprite->setTexture(*ghTex);

                Vector2u gsize = ghTex->getSize();

                const float maxW = 340.f;
                const float maxH = 240.f;
                float scaleX = maxW / static_cast<float>(gsize.x) * 1.7f;
                float scaleY = maxH / static_cast<float>(gsize.y) * 1.7f;
                float ghScale = std::min(scaleX, scaleY);
                this->greenhouseSprite->setScale(ghScale, ghScale);

                float gridRight = startX + cols * (shelfWidth - xSpacing * 150);
                float gx = gridRight + 18.f;
                float gy = startY;

                float availRight = static_cast<float>(this->getSize().x) - (maxW + 20.f);
                if (gx > availRight) gx = availRight;
                if (gx < startX) gx = startX + 10.f;

                float finalX = gx + 200.f;
                float finalY = gy;

                this->greenhouseSprite->setPosition(finalX, finalY);
                this->greenhousePosition = this->greenhouseSprite->getPosition();

                this->draw(*this->greenhouseSprite);
            }
        }
    }

    void displayStore() {
        this->displayShelves();
        this->displayCustomerStaff();
        this->displayCareStaff();
    }  

    void displayCustomerStaff(){
        // Load texture only once
        if (customerStaffSprite.getTexture() == nullptr) {
            Texture* customerStaffIMG = loadTexture("Staff/customerStaff_table.png");
            if (customerStaffIMG) {
                customerStaffSprite.setTexture(*customerStaffIMG);
                Vector2u texSize = customerStaffIMG->getSize();

                float desiredSize = 250.f; 
                float scale = (desiredSize / texSize.y);
                customerStaffSprite.setScale(scale, scale);

                float iconX = 10.f;  
                float iconY = this->getSize().y - desiredSize - 10.f;  
                customerStaffSprite.setPosition(iconX, iconY);
                
                // Store original position
                customerStaffOriginalPos = Vector2f(iconX, iconY);
            }
        }

        this->draw(customerStaffSprite);
    }

    void displayCareStaff() {
        if (!inventory) {
            std::cout << "Missing inventory" << std::endl;
            return;
        }

        // Load texture only once
        if (careStaffSprite.getTexture() == nullptr) {
            Texture* staffTexture = loadTexture("Staff/careStaff.png");
            if (!staffTexture) {
                staffTexture = loadTexture("assets/Staff/caretaker.png");
            }

            if (staffTexture) {
                careStaffSprite.setTexture(*staffTexture);
                Vector2u texSize = staffTexture->getSize();

                float staffSize = 200.f;
                float scale = (staffSize / std::max(texSize.x, texSize.y)) * 0.7f;
                careStaffSprite.setScale(scale, scale);

                // Start position at greenhouse
                careStaffSprite.setPosition(greenhousePosition.x + 180.f, greenhousePosition.y + 150.f);
            }
        }

        this->draw(careStaffSprite);
    }

    // Care Staff movement methods
    void moveCareStaffToInventory() {
        careStaffTarget = Vector2f(180.f, 100.f);
        isMovingCareStaff = true;
        // std::cout << "Care staff moving to inventory..." << std::endl;
    }

    void moveCareStaffToGreenhouse() {
        careStaffTarget = Vector2f(greenhousePosition.x + 180.f, greenhousePosition.y + 150.f);
        isMovingCareStaff = true;
        // std::cout << "Care staff returning to greenhouse..." << std::endl;
    }

    void moveCareStaffTo(float x, float y) {
        careStaffTarget = Vector2f(x, y);
        isMovingCareStaff = true;
        // std::cout << "Care staff moving to custom position (" << x << ", " << y << ")..." << std::endl;
    }

    bool isCareStaffMoving() const {
        return isMovingCareStaff;
    }

    // Customer Staff movement methods
    void moveCustomerStaffToInventory() {
        customerStaffTarget = Vector2f(180.f, 200.f);
        isMovingCustomerStaff = true;
        // std::cout << "Customer staff moving to inventory..." << std::endl;
    }

    void moveCustomerStaffBack() {
        customerStaffTarget = customerStaffOriginalPos;
        isMovingCustomerStaff = true;
        // std::cout << "Customer staff returning to original position..." << std::endl;
    }

    void moveCustomerStaffTo(float x, float y) {
        customerStaffTarget = Vector2f(x, y);
        isMovingCustomerStaff = true;
        // std::cout << "Customer staff moving to custom position (" << x << ", " << y << ")..." << std::endl;
    }

    bool isCustomerStaffMoving() const {
        return isMovingCustomerStaff;
    }
};
#endif