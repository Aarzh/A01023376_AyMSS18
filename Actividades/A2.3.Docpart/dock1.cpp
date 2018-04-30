
#include <iostream>
#include <string>
#include <list>
using namespace std;

class DocPart 
{
	public:
		string text;
		virtual string toHTML()=0;
		virtual string toLatex()=0;
		virtual string toText()=0;
};
class Text:public DocPart
{
	public:
	string toHTML()
	{
		return text;
	}
	string toLatex()
	{
		return text;
	}
	string toText()
	{
		return text;
	}			
};
class Bold:public DocPart
{
	public:
	string toHTML()
	{
		return "<b>"+text+"</b>";
	}
	string toLatex()
	{
		return "\\textbf{"+text+"}";
	}
	string toText()
	{
		return text;
	}	
};
class HyperLink:public DocPart
{
	public:
		string URL;
		public:
		string toHTML()
		{
			return "<a href='"+URL+"'>"+text+"</a>";
		}
		string toLatex()
		{
			return "\\href{"+URL+"}{"+text+"}";
		}
		string toText()
		{
			return text;
		}		
};
class Document
{
	public:
		list<DocPart*> docpart;
		string toHTML()
		{
			string out ="";
			for(DocPart* d: docpart)
			{
				out += d->toHTML();
			}
			return out;
		}
		string toLatex()
		{
			string out ="";
			for(DocPart* d: docpart)
			{
				out += d->toLatex();
			}
			return out;
		}	
		string toText()
		{
			string out ="";
			for(DocPart* d: docpart)
			{
				out += d->toText();
			}
			return out;
		}		
};
class IVisitor
{
	public:
		void 	
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
	cout<<d.toHTML()<<endl;
	cout<<d.toLatex()<<endl;
	cout<<d.toText()<<endl;	
}