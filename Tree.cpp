#include "Tree.h"

Tree::Tree(){
    age = 0;
    initialAge = 0;
}

std::string Tree::blossomDesc(){
    if (blossom == false)
      return "resting";
    else
      return "blossoming";
}

std::string Tree::treeAge(){
    if (age <= 200)
      return "sapling";
    else if (age > 200 && age <= 400)
      return "thin branch in the ground";
    else if (age > 400)
      return "tree";
}

std::string Tree::treeHealth(){
    if (thirst == 0)
        printf("wilting");
    if (thirst > 0 && thirst <= 50)
        printf("sunlight is poking through holes in the leaves.");
    if (thirst > 50)
        printf("filtering light through it's leaves");
}

void Tree::updateTreeAge(int time){
      age = time;
}
