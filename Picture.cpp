#include "Picture.h"
#include<cstring>
Picture::Picture():height(0),width(0),data(0){};
Picture::Picture(const char* const* array,int n){
	int w=0,i;
	for(i=0;i<n;i++)
		w=Picture::max(w,strlen(array[i]));
	init(n,w);
	for(i=0;i<n;i++){
		const char* src=array[i];
		int len=strlen(src);
		int j=0;
		while(j<len){
			position(i,j)=src[j];
			++j;
		}
                while(j<width){
			position(i,j)=' ';
			++j;
		}
	}
}
Picture::Picture(const Picture& p):height(p.height),width(p.width),data(new char[p.height*p.width]){
	copyblock(0,0,p);
}
Picture::~Picture(){
	delete [] data;
}

Picture& Picture::operator=(const Picture& p){
	if(this !=&p){
		delete [] data;
		init(p.height,p.width);
		copyblock(0,0,p);
	}
	return *this;
}
void Picture::copyblock(int row,int col,const Picture& p){
	for(int i=0;i<p.height;++i){
		for(int j=0;j<p.width;++j)
			position(i+row,j+col)=p.position(i,j);
	}
}
ostream& operator<<(ostream& o,const Picture& p){
	for(int i=0;i<p.height;++i){
		for(int j=0;j<p.width;++j)
			o<<p.position(i,j);
                o<<endl;
	}
	return o;
}
