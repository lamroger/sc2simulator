class Zerg {
  
  // Units
  class drone;
  class overlord;
  class zergling;
  class queen;
  class overseer;
  class roach;
  class baneling;
  class hydralisk;
  class infestor;
  class mutalisk;
  class corruptor;
  class ultralisk;
  class broodlord;
  
  // Buildings
  //class extractor;
  class hatchery;
  class evolution_chamber;
  class spawning_pool;
  class roach_warren;
  class baneling_nest;
  class lair;
  class hydralisk_den;
  class infestation_pit;
  class spire;
  class nydus_network;
  class hive;
  class ultralisk_cavern;
  class greater_spire;
  
  // Defensive Structures
  // calculate when defending?
  //class spore_crawler;
  //class spine_crawler;
  
public:
  Zerg();
  
  
private:
  int workers;
  int mining_bases;
  int army_value;
  int larva;
  int max_supply;
  
  int minerals;
  int gas;
  
}