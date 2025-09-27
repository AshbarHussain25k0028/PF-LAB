#include <stdio.h>
int main(){
	float Shape,choice,area,perimeter,radius,length,height,base,side1,side2;
	printf("enter your desired shape\n");
	printf("1.Circle\n");
	printf("2.Triangle\n");
	printf("3.Square\n");
	scanf("%f",&Shape);
	switch((int)Shape){
		case 1:
			printf("enter radius\n");
			scanf("%f",&radius);
			printf("Do you want to calculate area or the perimeter?\n");
			printf("1.Area,2.Perimeter\n");
			scanf("%f",&choice);
			switch((int)choice){
				case 1:
					area = 3.142*(radius*radius);
					printf("area is : %.2f\n",area);
				break;
				case 2:
					perimeter = 2*3.142*radius;
					printf("perimeter is : %.2f\n",perimeter);
				break;
				default: printf("invalid choice\n");
			}
		break;
		case 2:
			printf("enter height\n");
			scanf("%f",&height);
			printf("enter base\n");
			scanf("%f",&base);
			printf("Do you want to calculate area or the perimeter?\n");
			printf("1.Area,2.Perimeter\n");
			scanf("%f",&choice);
			switch((int)choice){
				case 1:
					area = 0.5*base*height;
					printf("area is : %.2f\n",area);
				break;
				case 2:
					printf("enter length of 2 sides of triangle\n");
					scanf("%f",&side1);
					scanf("%f",&side2);
					perimeter = base+side1+side2;
					printf("perimeter is : %.2f\n",perimeter);
				break;
				default: printf("invalid choice\n");
			}
		break;
		case 3:
			printf("enter length\n");
			scanf("%f",&length);
			printf("Do you want to calculate area or the perimeter?\n");
			printf("1.Area,2.Perimeter\n");
			scanf("%f",&choice);
			switch((int)choice){
				case 1:
					area = length*length;
					printf("area is : %.2f\n",area);
				break;
				case 2:
					perimeter = length*4;
					printf("perimeter is : %.2f\n",perimeter);
				break;
				default: printf("invalid choice\n");
			}
		break;
		default: printf("invalid input\n");
	}
}


