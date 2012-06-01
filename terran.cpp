class Terran::terranbuildings{
	public:
   		terranbuildings();   
   		bool add(string); //when player builds new building
   		int howmany(string);
   	private:
   		int count[15];	//keeps track of the number of each building

}

Zerg::terranbuildings::terranbuildings(){
	for(int i =0; i<15; i++)
	{
		count[i] = 0;
	}
}

bool Terran::terranbuildings::add(string building)
{
    switch(building) {
    
	case "command center":     // count[0]
   	 count[0]++;
   	 
    case "orbital command":   	 // count[1]
   	 if(count[0] == 0) {
   		 cout << "No command centers to upgrade" << endl;
   		 break;
   	 }
	 count[1]++;
   	 
    case "planetary fortress":   	 // count[2]
   	 if(count[0] == 0) {
   		 cout << "No command centers to upgrade" << endl;
   		 break;
   	 }
	 count[2]++;   

	case "supply depot"://count[3]
   	 count[3]++;
   	 
	case "refinery"://count[4]
   	 count[4]++;
   	 
	case "barracks":    //count[5]
   	 count[5]++;
   	 
	case "engineering bay"://count[6]
   	 count[6]++;
   	 
	case "bunker"://count[7]
   	 count[7]++;
    
	case "missile turret":    //count[8]
   	 count[8]++
    
	case "sensor tower":    //count[9]
   	 count[9]++;
    
	case "factor":    //count[10]
   	 count[10]++;
   	 
	case "ghost academy":    //count[11]
   	 count[11]++;
   	 
	case "armory":    //count[12]
   	 count[12]++;
    
	case "starport"://count[13]
   	 count[13]++;
	 
	case "tech lab": // count[14]
		count[14]++;
    
    default:
   	 cout << "Not valid building" << endl;
   	 return false;
    
    }
    
    return;
}

int Terran::terranbuildings::howmany(string building)
{
    switch(building) {
    
	case "command center":     // count[0]
   	 return count[0];
   	 
    case "orbital command":   	 // count[1]
	 return count[1];
   	 
    case "planetary fortress":   	 // count[2]
	 return count[2];   

	case "supply depot"://count[3]
   	 return count[3];
   	 
	case "refinery"://count[4]
   	 return count[4];
   	 
	case "barracks":    //count[5]
   	 return count[5];
   	 
	case "engineering bay"://count[6]
   	 return count[6];
   	 
	case "bunker"://count[7]
   	 return count[7];
    
	case "missile turret":    //count[8]
   	 return count[8];
    
	case "sensor tower":    //count[9]
   	 return count[9];
    
	case "factor":    //count[10]
   	 return count[10];
   	 
	case "ghost academy":    //count[11]
   	 return count[11];
   	 
	case "armory":    //count[12]
   	 return count[12];
    
	case "starport"://count[13]
   	 return count[13];
	 
	case "tech lab": // count[14]
	 return count[14];
    
    return;
}