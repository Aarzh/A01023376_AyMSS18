#include <iostream>
#include <string>
#include <list>
using namespace std;
class IVisitor;
class DocPart
{
	public:
		string text;
		virtual void accept(IVisitor*)=0;
};
class Text:public DocPart
{
	public:
		virtual void accept(IVisitor* visitor);
		
};
class Bold:public DocPart
{
	public:
		virtual void accept(IVisitor* visitor);
};
class HyperLink:public DocPart
{
	public:
		string URL;
		virtual void accept(IVisitor* visitor);
};
class IVisitor
{
	public:
		string out;
		virtual void visit(HyperLink)=0;
		virtual void visit(Text)=0;
		virtual void visit(Bold)=0;
		
};
class HTMLVisitor:public IVisitor
{
	public:
		void visit(HyperLink h)
		{
			out += "<a href='"+h.URL+"'>"+h.text+"</a>";
		}
		void visit(Bold b)
		{
			out += "<b>"+b.text+"</b>";
		}
		void visit(Text t)
		{
			out += t.text ;
		}
		
};
class TextVisitor:public IVisitor
{
	public:
			void visit(HyperLink h)
			{
				out += h.text;
			}
			void visit(Bold b)
			{
				out += b.text;
			}
			void visit(Text t)
			{
				out += t.text ;
			}
};
class LatexVisitor:public IVisitor
{
	public:
		void visit(HyperLink h)
		{
			out += "\\href{"+h.URL+"}{"+h.text+"}";
		}
		void visit(Bold b)
		{
			out += "\\textbf{"+b.text+"}";
		}
		void visit(Text t)
		{
			out += t.text;
		}
};

void Text::accept(IVisitor* visitor)
	{
		visitor->visit(*this);	
	}
void Bold::accept(IVisitor* visitor)
		{
			visitor->visit(*this);	
		}	
void HyperLink::accept(IVisitor* visitor)
	{
		visitor->visit(*this);	
	}	

class Document
{
	public:
		list<DocPart*> docpart;
		void accept(IVisitor* visitor)
		{
			for(DocPart* d: docpart)
			{
				d->accept(visitor);
			}
		
		}
	
};

int main() 
{
	Document d;
		Text t1;
		t1.text = "hola,vista";
		Bold t2;
		t2.text = "mi";
		HyperLink t3;
		t3.text = "pagina";
		t3.URL = "www.google.com";
		d.docpart.push_back(&t1);	
		d.docpart.push_back(&t2);	
		d.docpart.push_back(&t3);
		
		HTMLVisitor* htmlvisitor=new HTMLVisitor();
		d.accept(htmlvisitor);
		cout<<htmlvisitor->out;
	
}