#include <iostream>
#include <string>
using namespace std;

enum class Mobility {Walking, Swimming, Flying, Crawling};
class Animals
{
protected:
    string color;
    double weight;
    Mobility mobility;
    string Sound;
public:

    Animals(string color,double weight,Mobility m):color("1"),weight(1),mobility(m),Sound("")
    {
        setColor(color);
        setWeight(weight);
        /*setMobility(m);
        Mobility::Walking*/
    }
    void setColor(string val)
    {
        if(val>"0")
            color=val;
    }
    void setWeight(double val)
    {
        if(val>0)
            weight=val;
    }
    double getWeight()
    {
        return weight;
    }
    void setMobility(Mobility val)
    {
        mobility=val;
    }
    void SetSound(string sound){
        Sound=sound;
    }
    string getMadeof()
    {
        if(mobility==Mobility::Walking)
            return string("Walking");
        else if(mobility==Mobility::Swimming)
            return string("Swimming");
        else if(mobility==Mobility::Flying)
            return string("Flying");
        else if(mobility==Mobility::Crawling)
            return string("Crawling");
        else
            return string("");
    }
    virtual void animalDetails()=0;

   // friend ostream& operator <<(ostream& out, Animals m);

};

enum class MammalType {Dog, Cat, Elephant, Human};

class Mammal:public Animals
{
private:
    MammalType type;
public:
    Mammal(string color,double weight,Mobility m, MammalType mt):type(mt),Animals(color,weight,m)
    {
        if(type==MammalType::Dog){
            SetSound("woof");
        }
        else if(type==MammalType::Cat){
            SetSound("meow");
        }
        else if(type==MammalType::Elephant){
            SetSound("honk");
        }
        else if(type==MammalType::Human){
            SetSound("hello");
        }
    }

    void animalDetails()
    {
        cout<<"I'm a mammal of type: ";
        if(type==MammalType::Dog){
            cout<<"dog"<<endl;
        }
        else if(type==MammalType::Cat){
            cout<<"cat"<<endl;
        }
        else if(type==MammalType::Elephant){
            cout<<"elephant"<<endl;
        }
        else if(type==MammalType::Human){
            cout<<"human"<<endl;
        }
        cout<<"Mobility: "<<getMadeof()<<endl;
        cout<<"Color: "<<color<<endl;
        cout<<"Weight: "<<weight<<endl;
        cout<<"Sound: "<<Sound<<endl;
        cout<<endl;
    }

    friend ostream& operator <<(ostream& out, Mammal m);
};

ostream& operator<<(ostream &out, Mammal m){
    //m.animalDetails();
    out<<m.color<<endl;
    return out;
}

enum class BirdType {eagles, penguins, sparrows, ostriches};

class Bird:public Animals
{
private:
    BirdType type;
public:
    Bird(string color,double weight,Mobility m, BirdType mt):type(mt),Animals(color,weight,m)
    {
        if(type==BirdType::eagles){
            SetSound("caw");
        }
        else if(type==BirdType::penguins){
            SetSound("cackle");
        }
        else if(type==BirdType::sparrows){
            SetSound("chiii");
        }
        else if(type==BirdType::ostriches){
            SetSound("shriek");
        }
    }

    void animalDetails()
    {
        cout<<"I'm a bird of type: ";
        if(type==BirdType::eagles){
            cout<<"eagle"<<endl;
        }
        else if(type==BirdType::penguins){
            cout<<"penguin"<<endl;
        }
        else if(type==BirdType::sparrows){
            cout<<"sparrow"<<endl;
        }
        else if(type==BirdType::ostriches){
            cout<<"ostrich"<<endl;
        }
        cout<<"Mobility: "<<getMadeof()<<endl;
        cout<<"Color: "<<color<<endl;
        cout<<"Weight: "<<weight<<endl;
        cout<<"Sound: "<<Sound<<endl;
        cout<<endl;
    }

    friend void printDetails();
};

enum class FishType {salmon, sharks, goldfish, angelfish};

class Fish:public Animals
{
private:
    FishType type;
public:
    Fish(string color,double weight,Mobility m, FishType mt):type(mt),Animals(color,weight,m)
    {
        if(type==FishType::salmon){
            SetSound("salmon noises");
        }
        else if(type==FishType::sharks){
            SetSound("shark noises");
        }
        else if(type==FishType::goldfish){
            SetSound("glob glob");
        }
        else if(type==FishType::angelfish){
            SetSound("angelfish noises");
        }
    }

    void animalDetails()
    {
        cout<<"I'm a fish of type: ";
        if(type==FishType::salmon){
            cout<<"salmon"<<endl;
        }
        else if(type==FishType::sharks){
            cout<<"sharks"<<endl;
        }
        else if(type==FishType::goldfish){
            cout<<"goldfish"<<endl;
        }
        else if(type==FishType::angelfish){
            cout<<"angelfish"<<endl;
        }
        cout<<"Mobility: "<<getMadeof()<<endl;
        cout<<"Color: "<<color<<endl;
        cout<<"Weight: "<<weight<<endl;
        cout<<"Sound: "<<Sound<<endl;
        cout<<endl;
    }

};

enum class ReptileType {snakes, turtles, crocodiles, lizards};

class Reptile:public Animals
{
private:
    ReptileType type;
public:
    Reptile(string color,double weight,Mobility m, ReptileType mt):type(mt),Animals(color,weight,m)
    {
        if(type==ReptileType::snakes){
            SetSound("hisss");
        }
        else if(type==ReptileType::turtles){
            SetSound("slow turtle sounds");
        }
        else if(type==ReptileType::crocodiles){
            SetSound("clack clack");
        }
        else if(type==ReptileType::lizards){
            SetSound("lizard hisss");
        }
    }

    void animalDetails()
    {
        cout<<"I'm a Reptile of type: ";
        if(type==ReptileType::snakes){
            cout<<"snakes"<<endl;
        }
        else if(type==ReptileType::turtles){
            cout<<"turtles"<<endl;
        }
        else if(type==ReptileType::crocodiles){
            cout<<"crocodiles"<<endl;
        }
        else if(type==ReptileType::lizards){
            cout<<"lizards"<<endl;
        }
        cout<<"Mobility: "<<getMadeof()<<endl;
        cout<<"Color: "<<color<<endl;
        cout<<"Weight: "<<weight<<endl;
        cout<<"Sound: "<<Sound<<endl;
        cout<<endl;
    }

    friend void printDetails();
};

/**task 4**/
void sortAnimalWeight(Animals *animals[],int no){
    for(int i=0;i<no;i++){
        for(int j=i+1;j<no;j++){
            if(animals[i]->getWeight()< animals[j]->getWeight()){
                Animals* temp=animals[i];
                animals[i]=animals[j];
                animals[j]=temp;
            }
        }
    }
}


int main()
{
    Animals* f_list[100];

    /**task 1*/

    f_list[0] = new Mammal("Brown",50,Mobility::Walking,MammalType::Dog);
    //f_list[0]->animalDetails();

    f_list[1] = new Mammal("Black",5,Mobility::Walking,MammalType::Cat);
    //f_list[1]->animalDetails();

    f_list[2] = new Bird("Brown",25,Mobility::Flying,BirdType::eagles);
    //f_list[2]->animalDetails();

    f_list[3] = new Bird("Black",7,Mobility::Walking,BirdType::penguins);
    //f_list[3]->animalDetails();

    f_list[4] = new Fish("Blue",100,Mobility::Swimming,FishType::sharks);
    //f_list[4]->animalDetails();

    f_list[5] = new Fish("golden",0.2,Mobility::Swimming,FishType::goldfish);
    //f_list[5]->animalDetails();

    f_list[6] = new Reptile("ash",15,Mobility::Crawling,ReptileType::snakes);
    //f_list[6]->animalDetails();

    f_list[7] = new Reptile("faded brown",2,Mobility::Crawling,ReptileType::turtles);
    cout<<*f_list[0]<<endl;

    /**task 1 ends here*/

    /**
        task 2
        task 3 (Modify productDetails)
    */
    cout<<"BEFORE SORTING:"<<endl<<endl;
    for(int i=0; i<8; i++)
    {
        //f_list[i]->animalDetails();
    }

    /**task 2 ends here*/
    /**task 3 ends here*/

    /**task 4*/
    sortAnimalWeight(f_list,8);
    cout<<endl<<"AFTER SORTING:"<<endl<<endl;
    for(int i=0; i<8; i++)
    {
        //f_list[i]->animalDetails();
    }
    /**task 4 ends here*/

}

