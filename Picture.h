#ifndef Picture_h
#define Picture_h
#include<iostream>
using namespace std;
class Picture{
	private:
	    int height,width;
		char* data;
		char& position(int row,int col){
			return data[row*width+col];
		}
		char position(int row,int col) const {
			return data[row*width+col];
		}
		void copyblock(int,int,const Picture&);
	public:
	    Picture();
	    Picture(const char* const*,int);
		int max(int m,int n){
			return m>n?m:n;
		}
		void init(int h,int w){
			height = h;
			width = w+1;
			data = new char[height*width];
		}
		Picture(const Picture&);
		~Picture();
		Picture& operator=(const Picture&);
                friend ostream& operator<<(ostream&,const Picture&);
};
Picture frame(const Picture&);
Picture operator&(const Picture&,const Picture&);
Picture operator|(const Picture&,const Picture&);
#endif
