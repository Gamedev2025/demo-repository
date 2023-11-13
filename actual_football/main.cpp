#include<bits/stdc++.h>
#include <cmath>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

const int SCREEN_WIDTH = 1600;
const int SCREEN_HEIGHT = 900;
const int PLAY_BUTTON_POS_X = 620;
const int PLAY_BUTTON_POS_Y = 500;

enum State {
    MENU,
    NEW_PAGE,
    PLAY_WINDOW
};

void handleMenu(SDL_Renderer* renderer, SDL_Texture* startButtonTexture, SDL_Rect startButtonRect, bool& quit, State& currentState);
void handleNewPage(SDL_Renderer* renderer, SDL_Texture* newPageTexture, SDL_Texture* playButtonTexture, SDL_Rect playButtonRect, bool& quit, State& currentState);
void handlePlayWindow(SDL_Renderer* renderer, SDL_Texture* backgroundTexture, bool& quit);



int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Menu Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Surface* startButtonSurface = IMG_Load("enter2.png");
    if (startButtonSurface == nullptr) {
        printf("Unable to load image! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Texture* startButtonTexture = SDL_CreateTextureFromSurface(renderer, startButtonSurface);
    SDL_FreeSurface(startButtonSurface);

    if (startButtonTexture == nullptr) {
        printf("Unable to create texture from image! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_SetTextureColorMod(startButtonTexture, 150, 150, 150);
    SDL_Rect startButtonRect = { PLAY_BUTTON_POS_X, PLAY_BUTTON_POS_Y+100, 400, 300 };

    SDL_Surface* newPageSurface = IMG_Load("new_page.png");
    if (newPageSurface == nullptr) {
        printf("Unable to load new page image! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Texture* newPageTexture = SDL_CreateTextureFromSurface(renderer, newPageSurface);
    SDL_FreeSurface(newPageSurface);

    if (newPageTexture == nullptr) {
        printf("Unable to create texture from new page image! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Surface* playButtonSurface = IMG_Load("play_button.png");
    if (playButtonSurface == nullptr) {
        printf("Unable to load play button image! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Texture* playButtonTexture = SDL_CreateTextureFromSurface(renderer, playButtonSurface);
    SDL_FreeSurface(playButtonSurface);

    if (playButtonTexture == nullptr) {
        printf("Unable to create texture from play button image! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_SetTextureColorMod(playButtonTexture, 150, 150, 150);
    SDL_Rect playButtonRect = { PLAY_BUTTON_POS_X+50, PLAY_BUTTON_POS_Y+50, 300, 200 };

    // Load the background image for the play window
    SDL_Surface* backgroundPlaySurface = IMG_Load("background_play.png");
    if (backgroundPlaySurface == nullptr) {
        printf("Unable to load background play image! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Texture* backgroundPlayTexture = SDL_CreateTextureFromSurface(renderer, backgroundPlaySurface);
    SDL_FreeSurface(backgroundPlaySurface);

    if (backgroundPlayTexture == nullptr) {
        printf("Unable to create texture from background play image! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Surface* birdSurface = IMG_Load("bird.png");
    if (birdSurface == nullptr) {
        printf("Unable to load bird image! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }



    bool quit = false;
    State currentState = MENU;

    while (!quit) {
        if (currentState == MENU) {
            handleMenu(renderer, startButtonTexture, startButtonRect, quit, currentState);
        } else if (currentState == NEW_PAGE) {
            handleNewPage(renderer, newPageTexture, playButtonTexture, playButtonRect, quit, currentState);
        } else if (currentState == PLAY_WINDOW) {
            handlePlayWindow(renderer, backgroundPlayTexture, quit);

        }
    }

    SDL_DestroyTexture(startButtonTexture);
    SDL_DestroyTexture(newPageTexture);
    SDL_DestroyTexture(playButtonTexture);
    SDL_DestroyTexture(backgroundPlayTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    IMG_Quit();
    SDL_Quit();


    return 0;
}

void handleMenu(SDL_Renderer* renderer, SDL_Texture* startButtonTexture, SDL_Rect startButtonRect, bool& quit, State& currentState) {
    SDL_Event menuEvent;
    while (SDL_PollEvent(&menuEvent) != 0) {
        if (menuEvent.type == SDL_QUIT) {
            quit = true;
        } else if (menuEvent.type == SDL_MOUSEMOTION) {
            int mouseX, mouseY;
            SDL_GetMouseState(&mouseX, &mouseY);
            if (mouseX >= startButtonRect.x && mouseX <= (startButtonRect.x + startButtonRect.w) &&
                mouseY >= startButtonRect.y && mouseY <= (startButtonRect.y + startButtonRect.h)) {
                SDL_SetTextureColorMod(startButtonTexture, 255, 255, 255);
            } else {
                SDL_SetTextureColorMod(startButtonTexture, 150, 150, 150);
            }
        } else if (menuEvent.type == SDL_MOUSEBUTTONDOWN) {
            int mouseX, mouseY;
            SDL_GetMouseState(&mouseX, &mouseY);
            if (mouseX >= startButtonRect.x && mouseX <= (startButtonRect.x + startButtonRect.w) &&
                mouseY >= startButtonRect.y && mouseY <= (startButtonRect.y + startButtonRect.h)) {
                currentState = NEW_PAGE;
            }
        }
    }

    SDL_RenderClear(renderer);
    SDL_Surface* backgroundSurface = IMG_Load("background.png");
    SDL_Texture* backgroundTexture = SDL_CreateTextureFromSurface(renderer, backgroundSurface);
    SDL_FreeSurface(backgroundSurface);
    SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

    SDL_RenderCopy(renderer, startButtonTexture, NULL, &startButtonRect);
    SDL_RenderPresent(renderer);

    SDL_DestroyTexture(backgroundTexture);
}

void handleNewPage(SDL_Renderer* renderer, SDL_Texture* newPageTexture, SDL_Texture* playButtonTexture, SDL_Rect playButtonRect, bool& quit, State& currentState) {
    SDL_Event newPageEvent;
    while (SDL_PollEvent(&newPageEvent) != 0) {
        if (newPageEvent.type == SDL_QUIT) {
            quit = true;
        } else if (newPageEvent.type == SDL_MOUSEBUTTONDOWN) {
            int mouseX, mouseY;
            SDL_GetMouseState(&mouseX, &mouseY);
            if (mouseX >= PLAY_BUTTON_POS_X && mouseX <= (PLAY_BUTTON_POS_X + 400) &&
                mouseY >= PLAY_BUTTON_POS_Y && mouseY <= (PLAY_BUTTON_POS_Y + 300)) {
                currentState = PLAY_WINDOW;
            }
        }
    }

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, newPageTexture, NULL, NULL);

    // Check if the mouse is over the play button
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);
    if (mouseX >= playButtonRect.x && mouseX <= (playButtonRect.x + playButtonRect.w) &&
        mouseY >= playButtonRect.y && mouseY <= (playButtonRect.y + playButtonRect.h)) {
        // Glow effect when the cursor is over the play button
        SDL_SetTextureColorMod(playButtonTexture, 255, 255, 255);
    } else {
        SDL_SetTextureColorMod(playButtonTexture, 150, 150, 150); // Normal color
    }

    SDL_RenderCopy(renderer, playButtonTexture, NULL, &playButtonRect);
    SDL_RenderPresent(renderer);
}


// void handlePlayWindow(SDL_Renderer* renderer, SDL_Texture* backgroundTexture, bool& quit) {
//     // Load the bird texture
//     SDL_Surface* birdSurface = IMG_Load("bird.png");
//     if (birdSurface == nullptr) {
//         printf("Unable to load bird image! SDL_Error: %s\n", SDL_GetError());
//         return;
//     }

//     SDL_Texture* birdTexture = SDL_CreateTextureFromSurface(renderer, birdSurface);
//     SDL_FreeSurface(birdSurface);

//     if (birdTexture == nullptr) {
//         printf("Unable to create texture from bird image! SDL_Error: %s\n", SDL_GetError());
//         return;
//     }

//     // Set the initial position and size of the bird
//     SDL_Rect birdRect = { 130, 700, 100, 100 };  // Adjust the position and size as needed

//     // Flag to track if the bird is glowing
//     bool isGlowing = false;

//     // Flag to track if the bird is being dragged
//     bool isDragging = false;

//     // Initial position of the bird when dragging starts
//     int dragStartX = 0;
//     int dragStartY = 0;

//     // Flag to track if the bird is at the bottom of the window
//     bool isBirdAtBottom = false;

//     // Main game loop for the play window
//     SDL_Event playWindowEvent;
//     while (!quit) {
//         while (SDL_PollEvent(&playWindowEvent) != 0) {
//             if (playWindowEvent.type == SDL_QUIT) {
//                 quit = true;
//             } else if (playWindowEvent.type == SDL_MOUSEBUTTONDOWN) {
//                 int mouseX, mouseY;
//                 SDL_GetMouseState(&mouseX, &mouseY);

//                 // Check if the mouse click is on the bird
//                 if (mouseX >= birdRect.x && mouseX <= (birdRect.x + birdRect.w) &&
//                     mouseY >= birdRect.y && mouseY <= (birdRect.y + birdRect.h)) {
//                     isGlowing = true;  // Start glowing when clicked
//                     isDragging = true;  // Start dragging
//                     dragStartX = mouseX - birdRect.x;
//                     dragStartY = mouseY - birdRect.y;
//                 }
//             } else if (playWindowEvent.type == SDL_MOUSEMOTION) {
//                 if (isDragging) {
//                     // Update the bird's position while dragging
//                     int mouseX, mouseY;
//                     SDL_GetMouseState(&mouseX, &mouseY);
//                     birdRect.x = mouseX - dragStartX;
//                     birdRect.y = mouseY - dragStartY;
//                 }
//             } else if (playWindowEvent.type == SDL_MOUSEBUTTONUP) {
//                 if (isDragging) {
//                     // Stop glowing and dragging when the mouse button is released
//                     isGlowing = false;
//                     isDragging = false;

//                     // Calculate launch velocity based on the drag distance and direction
//                     int dragEndX = playWindowEvent.button.x;
//                     int dragEndY = playWindowEvent.button.y;
//                     int dragDistanceX = dragEndX - (birdRect.x + birdRect.w / 2);
//                     int dragDistanceY = dragEndY - (birdRect.y + birdRect.h / 2);

//                     // Adjust the launch speed factor as needed
//                     double launchSpeedFactor = 0.1;

//                     // Calculate launch velocity components
//                     double launchVelocityX = launchSpeedFactor * dragDistanceX;
//                     double launchVelocityY = launchSpeedFactor * dragDistanceY;

//                     // Main loop for bird's projectile motion
//                     while (birdRect.y < SCREEN_HEIGHT) {
//                         // Update the bird's position based on launch velocity
//                         birdRect.x += static_cast<int>(launchVelocityX);
//                         birdRect.y += static_cast<int>(launchVelocityY);

//                         // If the bird has reached the bottom of the window, stop updating its position
//                         if (birdRect.y + birdRect.h >= SCREEN_HEIGHT) {
//                             isBirdAtBottom = true;
//                             break;
//                         }

//                         // Restrict the bird's movement within the left and right boundaries
//                         if (birdRect.x < 0) {
//                             birdRect.x = 0;
//                         } else if (birdRect.x + birdRect.w > SCREEN_WIDTH) {
//                             birdRect.x = SCREEN_WIDTH - birdRect.w;
//                         }

//                         // Update the renderer
//                         SDL_RenderClear(renderer);
//                         SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
//                         SDL_RenderCopy(renderer, birdTexture, NULL, &birdRect);
//                         SDL_RenderPresent(renderer);

//                         // Introduce a small delay to control the frame rate
//                         SDL_Delay(5);
//                     }
//                 }
//             }
//         }

//         SDL_RenderClear(renderer);

//         // Render the background image
//         SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

//         // Render the bird texture with or without glow based on the isGlowing flag
//         if (isGlowing) {
//             // Glow effect when the bird is clicked
//             SDL_SetTextureColorMod(birdTexture, 255, 255, 255);
//         } else {
//             SDL_SetTextureColorMod(birdTexture, 150, 150, 150);  // Normal color
//         }

//         // Render the bird texture
//         SDL_RenderCopy(renderer, birdTexture, NULL, &birdRect);

//         // If the bird has reached the bottom of the window, break out of the loop
//         if (isBirdAtBottom) {
//             break;
//         }

//         // Add any additional rendering or logic here

//         SDL_RenderPresent(renderer);
//     }

//     // Destroy the bird texture when done
//     SDL_DestroyTexture(birdTexture);
// }






void handlePlayWindow(SDL_Renderer* renderer, SDL_Texture* backgroundTexture, bool& quit) {
    // Load the bird texture
    SDL_Surface* birdSurface = IMG_Load("bird.png");
    if (birdSurface == nullptr) {
        printf("Unable to load bird image! SDL_Error: %s\n", SDL_GetError());
        return;
    }

    SDL_Texture* birdTexture = SDL_CreateTextureFromSurface(renderer, birdSurface);
    SDL_FreeSurface(birdSurface);

    if (birdTexture == nullptr) {
        printf("Unable to create texture from bird image! SDL_Error: %s\n", SDL_GetError());
        return;
    }

    // Set the initial position and size of the bird
    SDL_Rect birdRect = { 130, 700, 100, 100 };  // Adjust the position and size as needed

    // Flags to track bird's state
    bool isGlowing = false;
    bool isDragging = false;
    bool isBirdAtBottom = false;  // Flag to track if the bird has reached the bottom

    // Initial position of the bird when dragging starts
    int dragStartX = 0;
    int dragStartY = 0;

    // Variables for launch velocity
    double launchSpeedFactor = 0.1;
    double launchVelocityX = 0.0;
    double launchVelocityY = 0.0;

    // Main game loop for the play window
    SDL_Event playWindowEvent;
    while (!quit) {
        while (SDL_PollEvent(&playWindowEvent) != 0) {
            if (playWindowEvent.type == SDL_QUIT) {
                quit = true;
            } else if (playWindowEvent.type == SDL_MOUSEBUTTONDOWN) {
                int mouseX, mouseY;
                SDL_GetMouseState(&mouseX, &mouseY);

                // Check if the mouse click is on the bird
                if (mouseX >= birdRect.x && mouseX <= (birdRect.x + birdRect.w) &&
                    mouseY >= birdRect.y && mouseY <= (birdRect.y + birdRect.h)) {
                    isGlowing = true;  // Start glowing when clicked
                    isDragging = true;  // Start dragging
                    isBirdAtBottom = false;  // Reset flag
                    dragStartX = mouseX - birdRect.x;
                    dragStartY = mouseY - birdRect.y;
                }
            } else if (playWindowEvent.type == SDL_MOUSEMOTION) {
                if (isDragging) {
                    // Update the bird's position while dragging
                    int mouseX, mouseY;
                    SDL_GetMouseState(&mouseX, &mouseY);
                    birdRect.x = mouseX - dragStartX;
                    birdRect.y = mouseY - dragStartY;

                    // Restrict the bird's movement within the top boundary
                    if (birdRect.y < 0) {
                        birdRect.y = 0;
                    }
                }
            } else if (playWindowEvent.type == SDL_MOUSEBUTTONUP) {
                if (isDragging) {
                    // Stop glowing and dragging when the mouse button is released
                    isGlowing = false;
                    isDragging = false;

                    // Calculate launch velocity based on the drag distance and direction
                    int dragEndX = playWindowEvent.button.x;
                    int dragEndY = playWindowEvent.button.y;
                    int dragDistanceX = dragEndX - (birdRect.x + birdRect.w / 2);
                    int dragDistanceY = dragEndY - (birdRect.y + birdRect.h / 2);

                    // Calculate launch velocity components
                    launchVelocityX = launchSpeedFactor * dragDistanceX;
                    launchVelocityY = launchSpeedFactor * dragDistanceY;

                    // Main loop for bird's projectile motion
                    while (birdRect.y < SCREEN_HEIGHT) {
                        // Update the bird's position based on launch velocity
                        birdRect.x += static_cast<int>(launchVelocityX);
                        birdRect.y += static_cast<int>(launchVelocityY);

                        // If the bird has reached the bottom, set its position to the bottom boundary
                        if (birdRect.y + birdRect.h >= SCREEN_HEIGHT) {
                            birdRect.y = SCREEN_HEIGHT - birdRect.h;
                            isBirdAtBottom = true;  // Set the flag
                        }

                        // If the bird has reached the top of the window, set its position to the top boundary
                        if (birdRect.y < 0) {
                            birdRect.y = 0;
                        }

                        // Restrict the bird's movement within the left and right boundaries
                        if (birdRect.x < 0) {
                            birdRect.x = 0;
                        } else if (birdRect.x + birdRect.w > SCREEN_WIDTH) {
                            birdRect.x = SCREEN_WIDTH - birdRect.w;
                        }

                        // Update the renderer
                        SDL_RenderClear(renderer);
                        SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
                        SDL_RenderCopy(renderer, birdTexture, NULL, &birdRect);
                        SDL_RenderPresent(renderer);

                        // Introduce a small delay to control the frame rate
                        SDL_Delay(5);
                    }
                }
            }
        }


        // Render the background image
        SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

        // Render the bird texture with or without glow based on the isGlowing flag
        if (isGlowing) {
            // Glow effect when the bird is clicked
            SDL_SetTextureColorMod(birdTexture, 255, 255, 255);
        } else {
            SDL_SetTextureColorMod(birdTexture, 150, 150, 150);  // Normal color
        }

        // Render the bird texture
        SDL_RenderCopy(renderer, birdTexture, NULL, &birdRect);

        // If the bird has reached the bottom, render a message
        if (isBirdAtBottom) {
            // You can add additional rendering or logic here
        }

        // Add any additional rendering or logic here

        SDL_RenderPresent(renderer);
    }

    // Destroy the bird texture when done
    SDL_DestroyTexture(birdTexture);

}