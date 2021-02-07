#include<iostream>
#include<string>
#include<cstdlib>
#include<fstream>
#include<iomanip>
#include<conio.h>
#include<sstream>

using namespace std;


class Item{
	
	int id,qtt;
	float price;
	string name;
	
	public :
		string getNamebyID(int ni){
			ifstream fid;
			fid.open("Items.txt",ios::in);
			
			while (true){
				fid>>id>>name>>price>>qtt;
				
				if(fid.good()){
				
					if(id == ni){
						return name;
					}
					
				}
				else{
					return "Not Found?";
					break;
				}
				
			}
			fid.close();
			
		}// end get name by Id
		
		
		
		float getPricebyID(int pi){
			
			ifstream fid;
				fid.open("Items.txt",ios::in);
				while (true){
					fid>>id>>name>>price>>qtt;
						if(fid.good()){
							if(pi==id){
								return price;
							}
					
						}
						else{
							return 0;
							break;
						}
				}
			fid.close();
			
		}// end get price by Id
		
		
		
		void updateQuantity(int uq,int si){
			
				int p=0;
				
				fstream upi;
				upi.open("Items.txt",ios::in|ios::out);
				
					while(true){
						
						upi>>id>>name>>price>>qtt;
						
							if(upi.good()){
								
								if(uq==id){
									upi.seekp(p,ios::beg);
									upi<<setw(6)<<id<<setw(10)<<name<<setw(5)<<price<<setw(5)<<qtt-si<<endl;
								}
								
							}
							else{
								break;
							}
				p=p+28;
			}
			upi.close();
			
		}// end update Quantity
		
		
		
		void createNewItem(){
			
			cout<<"-----Create New Item-----\n\n";
				cout<<" Enter Item Id : ";cin>>id;
				cout<<" Enter Item Name : ";cin>>name;
				cout<<" Enter Item Price : ";cin>>price;
				cout<<" Enter Item Quantity : ";cin>>qtt;
		
		}// end create new item
		
		
		
		void saveItem(){
			
			ofstream isave;
			
				isave.open("Items.txt",ios::app);
					isave<<setw(6)<<id<<setw(10)<<name<<setw(5)<<price<<setw(5)<<qtt<<endl;
					isave.close();	
					
		}// end save
		
		
		
		void showAll(){
			
			ifstream sll;
			
				sll.open("Items.txt",ios::in);
				
					cout<<"-----All Items-----\n\n";
					cout<<setw(6)<<"ID"<<setw(10)<<"Name"<<setw(10)<<"price"<<setw(10)<<"Quantity"<<endl<<endl;
						
						while (true){
							sll>>id>>name>>price>>qtt;
							
								if(sll.good()){
									
									if(id!=0){
										cout<<setw(6)<<id<<setw(10)<<name<<setw(10)<<price<<setw(10)<<qtt<<endl;
									}
								}
								else{
									break;
								}
						}
						sll.close();
							
		}//end show All
		
		
		
		void findItem(int fi){
			
			ifstream fid;
				fid.open("Items.txt",ios::in);
					cout<<"-----All Items-----\n\n";
					cout<<setw(6)<<"ID"<<setw(10)<<"Name"<<setw(10)<<"price"<<setw(10)<<"Quantity"<<endl<<endl;
						
						while (true){
							fid>>id>>name>>price>>qtt;
					
								if(fid.good()){
									
									if(fi==id){
										cout<<setw(6)<<id<<setw(10)<<name<<setw(10)<<price<<setw(10)<<qtt<<endl;
									}
								}
								else{
									break;
								}
						}
						fid.close();
		
		}// end find item
		
		
		
		void updateItem(int upid){
			int p=0;
			fstream upi;
				
				upi.open("Items.txt",ios::in|ios::out);
					
					while(true){
						upi>>id>>name>>price>>qtt;
							
							if(upi.good()){
								
								if(upid==id){
									cout<<"-----Update New Item Details-----\n\n";
									cout<<" Enter New Price : ";cin>>price;
									cout<<" Enter New Quatity : ";cin>>qtt;
										
										upi.seekp(p,ios::beg);
											upi<<setw(6)<<id<<setw(10)<<name<<setw(5)<<price<<setw(5)<<qtt<<endl;	
								}
							}
				else{
					break;
				}
				p=p+28;
			}
			upi.close();	
		}// end update item
		
		
		
		
		void deleteItem(int delit){
			int p=0;
			fstream del;
			del.open("Items.txt",ios::in|ios::out);
			while (true){
				del>>id>>name>>price>>qtt;
					if(del.good()){
					
						if(delit==id){
							del.seekp(p,ios::beg);
							del<<setw(6)<<0<<setw(10)<<"x"<<setw(5)<<0<<setw(5)<<0<<endl;
						}
					}
					
					else{
						break;
					}
			}
			del.close();	
		}// end delete item
		
		
		
		
};// end item class
class Bill:Item{
	
		string ftos(float f){
			stringstream s;
			s << f;
			return s.str();
		}//float to string
		
		float ttl=0,cash;
		string bill="##shop name##\n\n";
			public:
				void createBill(){
					system("cls");
					cout<<"Enter '0' for Item ID to finish the Bill\n\n";
					while(true){
						int itemId,Q;
						cout<<"Enter Item Id : ";cin>>itemId;
						if(itemId == 0){
							break;
						}
						cout<<getNamebyID(itemId)<<" Enter Quantity : ";cin>>Q;
						updateQuantity(itemId,Q);
						
						
						//string strp(to_string(getPricebyID(itemId)*Q));
						
						bill = bill+getNamebyID(itemId)+"\n\t "+ftos(getPricebyID(itemId))+"x"+ftos(Q)+" = "+ftos(getPricebyID(itemId)*Q)+"\n";
						ttl = ttl + getPricebyID(itemId)*Q;
						
						
					}
					system("cls");
					cout<<bill<<endl;
					cout<<"------------------------------------"<<endl;
					cout<<"total      "<<ttl<<endl;
					cout<<"enter cash : ";cin>>cash;
					if(ttl <= cash){
						cout<<"balance : "<<cash - ttl<<endl;
					}else{
						cout<<"not enugh cash"<<endl;	
					}
					
					
					
					
					
					
				}
				
	
	
	
}; // end  class Bill : Item
class Menu:Item{
	public:
		void anyKey(){
			cout<<" Press any key to Back********************";
			getch();
			
		}// end anyKey
		
		
		void itemMenu(){
			
			while (true){
				system("cls");
				int choice;
				cout<<"-----Select Your Choice-----\n\n";
				cout<<" Press 1 to Add New Item"<<endl;
				cout<<" Press 2 to Show All Item"<<endl;
				cout<<" Press 3 to Find Item"<<endl;
				cout<<" Press 4 to Update Item"<<endl;	
				cout<<" Press 5 to Delete Item"<<endl;
				cout<<" Press 0 to Back\n"<<endl;
				cout<<" ";cin>>choice;
				
					if(choice==0)	{
						break;
					}
					
					else if(choice==1){
						system("cls");
						createNewItem();
						saveItem();		
					}
					
					else if(choice==2){
						system("cls");
						showAll();
						anyKey();
						
						
					}
					
					else if(choice==3){
						system("cls");
						int fidi;
						cout<<"Enter Item ID : ";cin>>fidi;
						findItem(fidi);
						anyKey();
					}
					
					
					else if(choice==4){
						system("cls");
						int upid;
						cout<<"Enter Item ID : ";cin>>upid;
						updateItem(upid);
					
					}
					
					
					else if(choice==5){
						system("cls");
						int delit;
						cout<<"Enter Item ID : ";cin>>delit;
						deleteItem(delit);
						
					}
				
					
					
								
			}// end while
			
			
		}// end itemMenu
		
		
		
	void mainMenu(){
		while (true){
			system("cls");
			cout<<"\n!!!!!     Welcome to Bill Managemant System     !!!!!"<<endl;
			int option;
			cout<<"\n Press 1 to Items"<<endl;
			cout<<" Press 2 to Create New Bill"<<endl;
			cout<<" Press 0 to Exit\n"<<endl;
			cout<<" ";cin>>option;
			
			if(option==0){
				break;
			}
			else if(option==1){
				system("cls");
				Menu items;
				items.itemMenu();
				
				
			}
			else if(option==2){
				system("cls");
				Bill b;
				b.createBill();
				anyKey();
				
				
			}
			
			
		}// end while
		
		
	}//mainManu
	
	
	
};// end Manu : item  class
int main(){
	Menu m1;
	m1.mainMenu();
	
	
	
	
	return 0;
	
}// End of the main function
