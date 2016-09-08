#include "Picture.h"
using namespace std;

char* init[]={"pairs","in the","Spring"};
int main(){
	Picture p(init,3);
	//cout<<p<<endl;

	Picture q=frame(p);
	//cout<<q<<endl;
	
	Picture r=p|q;
	cout<<r<<endl;
	
	Picture s=q&q;
	cout<<s<<endl<<frame(s)<<endl;
	
	return 0;
}
