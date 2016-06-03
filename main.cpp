#include <3ds.h>
#include <stdio.h>
#include <string.h>
#include "Environment.c"
#include "Tree.c"

// Main runtime for the game
float startGame();

// Activated based on initial user input
void noGame();
void misunderstoodGame();


// MAIIN METHOD, prompts what the user wants to do
int main()
{
    // Initiliazes graphics, apt, and hid modules
    gfxInitDefault();
    aptInit();
    hidInit();

    // Creates a console on the top screen for us to print to
    consoleInit(GFX_TOP, NULL);

    // Well do they want to?
    printf("Play the Game? Start - Yes; B - No");

    // Main loop for prompting someone to play the game
    while(true){

        // Scans for what button is being what
        hidScanInput();
        u32 kDown = hidKeysDown();


        // What to do based on key selection, start game, say "o" then wait for them to press a/b to exit, or feeling like the user doesn't understand
        // Me sometimes
        if (kDown & KEY_START)
            startGame();
        else if (kDown & KEY_B) {
            noGame();
        }
        else {
            misunderstoodGame();
        }

        // Flush and swap buffers
        gfxFlushBuffers();
        gfxSwapBuffers();

        // Wait for VBlank to respond
        gspWaitForVBlank();

    }


    hidScanInput();
    kDown = hidKeysDown();

    while (!kDown & KEY_A){

        printf("How did you get here?")
        // Seriously what
        gfxFlushBuffers();
        gfxSwapBuffers();

        // Take a seat while we wait why don't you, you've already broken my program
        // so why shouldn't you break my chair?
        gspWaitForVBlank();
    }

    gfxExit();
    hidExit();
    aptExit();
    return 0;
}




//THIS IS WHERE THE REAL GAME BEGINS
float startGame()
{
        // Starts your Environment
        Environment home();

        // Creates your tree
        Tree yourTree();

        // All save loading will happen here, too; will be implemented later

        // Real Main Loop. hopefully this doesn't break anything
        while (aptMainLoop()){
            hidScanInput();
            kDown = hidKeysDown();

            // Aging the tree
            yourTree.updateTreeAge(home.getTime());


            // Waits uNtIL THE VBLANK ARRIIIIVEEEESSS OOOO
            gspWaitForVBlank();

            // o shit whaddup
            printf("Your %s %s is %s."
                  ,yourTree.blossomDesc().c_str(), yourTree.treeAge().c_str()
                  , yourTree.treeHealth().c_str());

            // User input will happen here once I get the rest of this program working

            gfxFlushBuffers();
            gfxSwapBuffers();

            gspWaitForVBlank();
        }
        gfxExit();
        hidExit();
        aptExit();

        return 0;
}

void noGame(){
      do {
          hidScanInput();
          kDown = hidKeysDown();
          printf("o");

          // Flush and swap buffers
          gfxFlushBuffers();
          gfxSwapBuffers();

          // Wait for VBlank
          gspWaitForVBlank();
      } while (!kDown & KEY_A || !kDown & KEY_B);

      // Closes down modules, brings user back to the home screen/homebrew menu
      gfxExit();
      hidExit();
      aptExit();
      return 0;
}

void misunderstoodGame(){

  do {
      hidScanInput();
      kDown = hidKeysDown();
      printf("o");
      printf("I feel like we just don't understand each other sometims");

  } while (kDown & KEY_A);

  printf("I feel like we just don't understand each other sometims");
}
