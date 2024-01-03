#include<bits/stdc++.h>
using namespace std;

int compare(vector<pair<int, string>>& v, int n){
    int cou=0;
    for(int i=0;i<v.size();i++){
        if(v[i].first>n) cou++;
    }
    return cou;
}

int count(vector<pair<int, string>>& v, int n){
    int cou=0;
    for(int i=0;i<v.size();i++){
        if(v[i].first==n) cou++;
    }
    return cou;
}

int main()
{
    vector<pair<int, string>> v;
    vector<int> scores;
    const int MAX = 80;
    char buffer[MAX];
    ifstream infile("TEST.TXT");
    int cou=1;
    while( !infile.eof() )
    {
        string name="", score="";
        infile.getline(buffer, MAX);
        int i;
        for(i=0;buffer[i]!=',';i++){
            name+=buffer[i];
        }
        i++;
        for( ;buffer[i]!='\0';i++){
            score+=buffer[i];
        }
        int num= stoi(score);
        v.push_back({num, name});
        scores.push_back(num);

    }
    infile.close();

    cout<<"\tTASK 1\n";
    sort(v.begin(), v.end());
    for(int i=0;i<v.size();i++){
        string buff=v[i].second;
        for(int i=0;i<buff.size();i++){
            if(buff[i]=='e' || buff[i]=='a' || buff[i]=='i' || buff[i]=='o' || buff[i]=='u'){
                int num = rand()%10;
                cout<<num;
            }
            else cout<<buff[i];
        }
        cout<<" "<<v[i].first<<endl;
    }

    cout<<"\n\tTASK 2\n";
    stable_sort(v.begin(),v.end(), greater<pair<int,string>>());
    for(int i=0;i<5;i++){
        cout<<v[i].second<<endl;
    }
    stable_sort(scores.begin(), scores.end(), greater<int>());

    cout<<"\n\tTASK 3\n";
    reverse(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        cout<<v[i].second<<endl;
    }
    reverse(scores.begin(), scores.end());

    cout<<"\n\tTASK 4\n";
    cout<<"using vector of pairs: "<<compare(v,30)<<endl;

    int it= (upper_bound(scores.begin(), scores.end(), 30)) - scores.begin();
    cout<<"using stl: "<< scores.size()-it <<endl;

    cout<<"\n\tTASK 5\n";
    cout<<"using vector of pairs: "<<count(v,51)<<endl;
    cout<<"using stl: "<<count(scores.begin(), scores.end(), 51)<<endl;

    cout<<"\n\tTASK 6\n";
    vector<pair<int, string>> extra;
    extra=v;
    for(int i=0;i<v.size();i++){
        if(v[i]!=extra[i]){ cout<<"not copied properly"; break;}
    }
    vector<int> extra_score=scores;
    if(scores==extra_score) cout<<"ok"<<endl;

    cout<<"\n\tTASK 7\n";
    extra_score.clear();
    extra.clear();

    while(1){
        int scr; string p_name;
        cin>>scr;
        if(scr==-1) break;
        cin>>p_name;
        extra_score.push_back(scr);
        extra.push_back({scr, p_name});
    }
    vector<int> desti(scores.size()+extra_score.size());
    vector<pair<int, string>> destp(v.size()+extra.size());
    merge(scores.begin(),scores.end(), extra_score.begin(), extra_score.end(), desti.begin());
    merge(v.begin(),v.end(), extra.begin(), extra.end(), destp.begin());
    cout<<"for the paired vector: "<<endl;
    for(int i=0;i<destp.size();i++){
        cout<<destp[i].second<<" "<<destp[i].first<<endl;
    }
    cout<<"for the score vector: "<<endl;
    for(int i=0;i<desti.size();i++){
        cout<<desti[i]<<endl;
    }

    cout<<"\n\tTASK 8\n";
    int sum=0;
    cout<<"average of the entire array is: "<<float(accumulate(scores.begin(), scores.end(), sum))/scores.size()<<endl;
}
