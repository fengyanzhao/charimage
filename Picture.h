#ifndef Picture_h
#define Picture_h
#include<iostream>
using namespace std;
class Picture{
	private:
	    int height,width;
		char* data;
		//用position(int row,int col)表示第row行col列的位置的字符
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
		static int max(int m,int n){
			return m>n?m:n;
		}
		void init(int h,int w){
			height = h;
			width = w;
			data = new char[height*width];
		}
		Picture(const Picture&);
		~Picture();
		Picture& operator=(const Picture&);
		void clear(int,int,int,int);
        friend ostream& operator<<(ostream&,const Picture&);
		friend Picture frame(const Picture&);
		friend Picture operator&(const Picture&,const Picture&);
		friend Picture operator|(const Picture&,const Picture&);
};
#endif
