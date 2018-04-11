#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Subject {
    vector < class Observer * > views;
    string value;
  public:
    void attach(Observer *obs) {
        views.push_back(obs);
    }
    void speak(string msg) {
        value = msg;
        notifyAll();
    }
    string getMsg() {
        return value;
    }
    void notifyAll();
};

class Observer {
    // 2. "dependent" functionality
    Subject *model;
    string denom;
  public:
    Observer(Subject *mod, string msg) {
        model = mod;
        denom = msg;
        // 4. Observers register themselves with the Subject
        model->attach(this);
    }
    virtual void update() = 0;
  protected:
    Subject *getSubject() {
        return model;
    }
    string getMsg() {
        return denom;
    }
};

void Subject::notifyAll() {
  // 5. Publisher broadcasts
  for (int i = 0; i < views.size(); i++)
    views[i]->update();
}

class Candidate: public Observer {
  public:
    Candidate(Subject *mod, string msg): Observer(mod, msg){}
    void update() {
        string  v = getSubject()->getMsg();
        cout<<v<<" va a ganar"<<endl;
    }
};

class News: public Observer {
  public:
    News(Subject *mod, string msg): Observer(mod, msg){}
    void update() {
        string  v = getSubject()->getMsg();
        cout << "Reporting from "<<v<<" news"<<endl;
    }
};

int main() {
  Subject subj;
  Subject amlo;
  Subject anaya;
  Candidate AMLO(&amlo, "YA JABEN QUIEN JOY"); // 7. Client configures the number and
  Candidate ANAYA(&anaya, "RICARDO ANAYA, RICARDO ANAYA, NO TIENE CHILE TIENE UNA PAPAYA"); //    type of Observers
  News mvs(&subj, "VOTEN POR ALGUIEN");
  subj.speak("MVS");
  amlo.speak("AMLO");
  anaya.speak("ANAYA");
}

