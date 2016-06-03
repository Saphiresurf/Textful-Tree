#ifndef Tree_H
#define Tree_H

// Tree blueprint
class Tree
{
  public:
    Tree();

    // Return verbage relevant to blossom state
    std::string blossomDesc();

    // Return verbage relevant to age
    std::string treeAge();

    // Returns verbage relevant to health, dependant on water content
    std::string treeHealth();

    // For the environment to update the age of the tree
    void updateTreeAge(int time);

    void setThirst(int water);

  private:
    // Not introducing mortality...yet
    // Floor = 0; Ceiling = ???
    int age;
    int initialAge;
    // Water available can be absorbed by the tree, part of it
    // Will be lost to the environment while the tree absorbs it.
    // I suppose this should have a maximum, but maybe we'll introduce flooding
    // Floor = 0; Ceiling = ???
    int waterAvailable;
    // Lets make the floor for thirst be 0 and the ceiling 100
    // Floor = 0; Ceiling = 100
    int thirst;
    boolean blossom;
    boolean stump;
    std::string originalHome;
    std::string currentHome;

};

#endif
