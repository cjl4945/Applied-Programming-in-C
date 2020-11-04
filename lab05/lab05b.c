#include <stdio.h> 
/*Point*/
struct point {
	double x;
	double y; 
};
/* Student*/
struct student {	
	char f_name[256]; 
	char l_name[256]; 
	int u_id; 
};	
	
/*structure with pointers*/
typedef struct MyData {  
	char* name;
	unsigned int capacity;    /* Max # of elem can hold */
	unsigned int last_used;   /* Index of Last element  */
	char*    data;     	 /*  ptr to data           */
} myData;
	
int main() 
{ 	/*init point*/
	double x0,y0;         
	struct point* p0;             /* declaration    */
	struct point p1={2.5,-1.0};  /* initialization */
	p0 = &p1;              /* assignment */
	x0 = p0->x;            /* accessing members */
	y0 = p0->y;            /* with the . operator */	
	printf("p.x:%f, p.y:%f\n", x0, y0);

	/* init student*/
	struct student stu={"John", "Smith", 999};
	struct student* st;
	st = &stu;	
	printf("Name:%s, ID:%d\n", st->f_name, st->u_id);
	
	/* init and print myData*/
	myData  nada; 	/* data declaration 			*/
	myData* nada_p;  	/* pointer declaration 		*/
	nada_p = &nada;	/* pointers MUST point to data	*/	
	nada_p->name = "Bob";
	nada_p->capacity = 100;	/* for pointers use “->”	*/
	nada_p->data = "my private data";	
	printf("Name:%s, Capacity:%d, Data:%s\n", nada_p->name, nada_p->capacity, nada_p->data);
  
    return 0; 
} 