#include <iostream>

using namespace std;

class Impresora
{
public:
    virtual void printSimple() = 0;
    virtual void printFormat() = 0;
    virtual void printImgs() = 0;
    virtual void accept(class Visitor*) = 0;
};

class Laser : public Impresora{
public:
    void accept(Visitor*);
    void printSimple(){
        cout<<"Imprimiendo doc simple, desde laser"<<endl;
    }
    void printFormat(){
        cout<<"Imprimiendo doc con formato, desde laser"<<endl;
    }
    void printImgs(){
        cout<<"Imprimiendo imagen, desde laser"<<endl;   
    }
};

class Inyeccion : public Impresora{
public:
    void accept(Visitor*);
    void printSimple(){
        cout<<"Imprimiendo doc simple, desde Inyeccion"<<endl;
    }
    void printFormat(){
        cout<<"Imprimiendo doc con formato, desde Inyeccion"<<endl;
    }
    void printImgs(){
        cout<<"Imprimiendo imagen, desde Inyeccion"<<endl;   
    }
};

class Pdf : public Impresora{
public:
    void accept(Visitor*);
    void printSimple(){
        cout<<"Imprimiendo doc simple, desde pdf"<<endl;
    }
    void printFormat(){
        cout<<"Imprimiendo doc con formato, desde pdf"<<endl;
    }
    void printImgs(){
        cout<<"Imprimiendo imagen, desde pdf"<<endl;   
    }
};

class PostScript : public Impresora{
public:
    void accept(Visitor*);
    void printSimple(){
        cout<<"Imprimiendo doc simple, desde post script"<<endl;
    }
    void printFormat(){
        cout<<"Imprimiendo doc con formato, desde post script"<<endl;
    }
    void printImgs(){
        cout<<"Imprimiendo imagen, desde post script"<<endl;   
    }
};

class  Visitor{
public:
    virtual void visit(PostScript*) = 0;
    virtual void visit(Laser*) = 0;
    virtual void visit(Pdf*) = 0;
    virtual void visit(Inyeccion*) = 0;
};

class CountVisitor: public Visitor
{
  public:
    CountVisitor()
    {
        m_num_laser = m_num_pdf = m_num_postScript = m_num_inject = 0;
    }
     /*virtual*/void visit(PostScript*)
    {
        ++m_num_postScript;
    }
     /*virtual*/void visit(Inyeccion*)
    {
        ++m_num_inject;
    }
    /*virtual*/void visit(Pdf*)
    {
        ++m_num_pdf;
    }
    /*virtual*/void visit(Laser*)
    {
        ++m_num_laser;
    }
    void report_num()
    {
        cout << "Laser " << m_num_laser << ", Pdf " << m_num_pdf <<", Inyeccion "<<m_num_inject<<", PostScript "<<m_num_postScript<< '\n';
    }
  private:
    int m_num_laser, m_num_pdf, m_num_postScript, m_num_inject;
};

class CallVisitor: public Visitor
{
  public:
     /*virtual*/void visit(Laser *l)
    {
        l->printSimple();
    }
     /*virtual*/void visit(Inyeccion *i)
    {
        i->printFormat();
    }
     /*virtual*/void visit(Pdf *p)
    {
        p->printImgs();
    }
     /*virtual*/void visit(PostScript *ps)
    {
        ps->printImgs();
        ps->printFormat();
        ps->printSimple();
    }
};

void Laser::accept(Visitor *v)
{
    v->visit(this);
}

void Pdf::accept(Visitor *v)
{
    v->visit(this);
}

void Inyeccion::accept(Visitor *v)
{
    v->visit(this);
}

void PostScript::accept(Visitor *v)
{
    v->visit(this);
}

class Creator{
public:
    virtual Impresora* factoryMethod(char)=0;

    Impresora* createProduct(char tipo)
    {
        Impresora* myImpresion = factoryMethod(tipo);
        myImpresion->printSimple();
        myImpresion->printFormat();
        myImpresion->printImgs();
        return myImpresion;
    }
};

class ConcreteCreator : public Creator{
    Impresora* factoryMethod(char tipo){
        if(tipo=='L')
            return new Laser;
        else if(tipo == 'P')
            return new Pdf;
        else if(tipo == 'I')
            return new Inyeccion;
        else
            return new PostScript;
    }
};

class Singleton
{
    private:
        /* Here will be the instance stored. */
        static Singleton* instance;

        /* Private constructor to prevent instancing. */
        Singleton();

    public:
        /* Static access method. */
        static Singleton* getInstance();
};

/* Null, because instance will be initialized on demand. */
Singleton* Singleton::instance = 0;

Singleton* Singleton::getInstance()
{
    if (instance == 0)
    {
        instance = new Singleton();
    }

    return instance;
}

Singleton::Singleton()
{}

int main()
{
    Creator* cliente = new ConcreteCreator();
    Impresora* myImpresion = cliente->createProduct('F');
    Impresora *set[] = {
        new Inyeccion, new PostScript, new Pdf, new Laser, new Laser, new Inyeccion, 0
    };
    CountVisitor count_operation;
    CallVisitor call_operation;
    for (int i = 0; set[i]; i++)
    {
        set[i]->accept(&count_operation);
        set[i]->accept(&call_operation);
    }
    count_operation.report_num();
}