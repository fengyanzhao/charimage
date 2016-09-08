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
	//拷贝构造函数
	copyblock(0,0,p);
}
Picture::~Picture(){
	delete [] data;
}

void Picture::clear(int begx,int begy,int endx,int endy){
	for(int i=begx;i<=endx;i++)
		for(int j=begy;j<=endy;j++)
			position(i,j)=' ';
}

Picture& Picture::operator=(const Picture& p){
	//通过重载'='实现的拷贝构造函数
	if(this !=&p){
		delete [] data;
		init(p.height,p.width);
		copyblock(0,0,p);
	}
	return *this;
}
void Picture::copyblock(int row,int col,const Picture& p){
	//将p的源图像复制到以新对象的以(row,col)为起点的位置
	for(int i=0;i<p.height;++i){
		for(int j=0;j<p.width;++j)
			position(i+row,j+col)=p.position(i,j);
	}
}
ostream& operator<<(ostream& o,const Picture& p){
	//重载输出运算符"<<"
	for(int i=0;i<p.height;++i){
		for(int j=0;j<p.width;++j)
			o<<p.position(i,j);
                o<<endl;
	}
	return o;
}

Picture frame(const Picture& p){//构造边框，假设边框只有一个字符组成
	Picture r;
	r.init(p.height+2,p.width+2);
	for(int i=1;i<r.height-1;++i){
		r.position(i,0)='|';
		r.position(i,r.width-1)='|';
	}
	for(int i=1;i<r.width;i++){
		r.position(0,i)='-';
		r.position(r.height-1,i)='-';
	}
	r.position(0,0)='+';
	r.position(0,r.width-1)='+';
	r.position(r.height-1,0)='+';
	r.position(r.height-1,r.width-1)='+';
	r.copyblock(1,1,p);
	return r;
}
Picture operator&(const Picture& p,const Picture& q){//纵向连接
	Picture r;
	r.init(p.height+q.height,Picture::max(p.width,q.width));
	r.clear(0,0,r.height-1,r.width-1);
	r.copyblock(0,0,p);
	r.copyblock(p.height,0,q);
        return r;
}
Picture operator|(const Picture& p,const Picture& q){//横向连接
	Picture r;
	r.init(Picture::max(p.height,q.height),p.width+q.width);
	r.clear(0,0,r.height-1,r.width-1);
	r.copyblock(0,0,p);
	r.copyblock(0,p.width,q);
	return r;
}
