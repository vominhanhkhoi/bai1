// bai1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

struct Point
{
	double x, y;

	void input()
	{
		cout << "nhap toa do diem:\n";
		cout << "nhap x= "; cin >> x;
		cout << "nhap y= "; cin >> y;
	}

};

struct Segment
{
	Point A, B;

	Segment()  //contructor nhap tu console
	{
		cout << "nhap toa do diem A:\n";
		cout << "nhap x= "; cin >> A.x;
		cout << "nhap y= "; cin >> A.y;

		cout << "nhap toa do diem B:\n";
		cout << "nhap x= "; cin >> B.x;
		cout << "nhap y= "; cin >> B.y;
	}

	Segment(Point a,Point b) //contructor lay 2 diem
	{
		A = a;
		B = b;
	}


	double dodai()
	{
		double t = 0;
		t = sqrt(pow(B.x - A.x, 2) + pow(B.y - A.x, 2));
		return t;
	}
};

struct Line
{
	double a, b, c;
	Point M;
	void input()
	{
		cout << "nhap phuong trinh duong thang:\n";
		cout << "nhap a= "; cin >> a;
		cout << "nhap b= "; cin >> b;
		cout << "nhap c= "; cin >> c;
		cout << "nhap M(x) = "; cin >> M.x;
		cout << "nhap M(y) = "; cin >> M.y;

	}
};

struct Vector
{
	Point source, target;

	void input()
	{
		cout << "nhap toa do diem source cua vector :\n";
		cout << "nhap x= "; cin >> source.x;
		cout << "nhap y= "; cin >> source.y;
		cout << "nhap toa do diem target cua vector :\n";
		cout << "nhap x= "; cin >> target.x;
		cout << "nhap y= "; cin >> target.y;
	}

};

struct Triangle
{
	Point A, B, C;

	void input()
	{
		cout << "nhap toa do diem A:\n";
		cout << "nhap x= "; cin >> A.x;
		cout << "nhap y= "; cin >> A.y;

		cout << "nhap toa do diem B:\n";
		cout << "nhap x= "; cin >> B.x;
		cout << "nhap y= "; cin >> B.y;

		cout << "nhap toa do diem C:\n";
		cout << "nhap x= "; cin >> C.x;
		cout << "nhap y= "; cin >> C.y;
	}

	bool IsTriangle(Point a,Point b,Point c)
	{
		Segment ab(a,b), bc(b,c), ca(c,a);
	
		if (ab.dodai() + bc.dodai() <= ca.dodai() || ab.dodai() + ca.dodai() <= bc.dodai() || bc.dodai() + ca.dodai() <= ab.dodai())
			return false;
		else
			return true;
	}
};

struct Reangle
{
	Point A, B, C, D;

	void input()
	{
		cout << "nhap toa do diem A:\n";
		cout << "nhap x= "; cin >> A.x;
		cout << "nhap y= "; cin >> A.y;

		cout << "nhap toa do diem B:\n";
		cout << "nhap x= "; cin >> B.x;
		cout << "nhap y= "; cin >> B.y;

		cout << "nhap toa do diem C:\n";
		cout << "nhap x= "; cin >> C.x;
		cout << "nhap y= "; cin >> C.y;

		cout << "nhap toa do diem D:\n";
		cout << "nhap x= "; cin >> D.x;
		cout << "nhap y= "; cin >> D.y;
	}
};

struct Circle
{
	double tam, bankinh;

	void input()
	{
		cout << "nhap tam hinh tron ="; cin >> tam;
		cout << "nhap ban kinh hinh tron ="; cin >> bankinh;
	}

};


double cross(Point a, Point b, Point c)  //co the dung segment.dodai() de tinh x,y;
{
	double x1 = b.x - a.x;
	double y1 = b.y - a.y;

	double x2 = c.x - a.x;
	double y2 = c.y - a.y;

	return (x1 * y2 - y1 * x2);
}

struct Convexpoly
{
	int n;
	Point* ptr;
	
	Convexpoly()
	{
		cout << "nhap so diem cua convexpoly = "; cin >> n;
		ptr = NULL;
		ptr = new(nothrow) Point[n];

		if (!ptr) {
			cout << "memory allocation failed!";
		}
		else
		{
			int d = 1;
			for (int i = 0; i < n; i++)
			{
				cout << "nhap toa do diem thu " << d << " :\n"; d++;
				cout << "nhap x= "; cin >> ptr[i].x;
				cout << "nhap y= "; cin >> ptr[i].y;
			}
		}
	}


	~Convexpoly()
	{
		delete ptr;
	}

	bool IsConvex()
	{
		double trc = 0, sau = 0;

		for (int i = 0; i < n; i++)
		{
			Point d1, d2, d3;

			d1.x = ptr[i].x;
			d1.y = ptr[i].y;

			d2.x = ptr[(i + 1) % n].x;
			d2.y = ptr[(i + 1) % n].y;

			d3.x = ptr[(i + 2) % n].x;
			d3.y = ptr[(i + 2) % n].y;

			sau = cross(d1, d2, d3);
			if (sau != 0)
			{
				if (trc * sau < 0) return 0;
				else trc = sau;
			}
		}
		return 1;
	}

};






int main()
{
	cout << "1: point \n";
	cout << "2: segment\n";
	cout << "3: line \n";
	cout << "4: vector \n";
	cout << "5: triangle\n";
	cout << "6: reangle \n";
	cout << "7: circle \n";
	cout << "8: convex poly \n";
	cout << "chon doi tuong = ";

	int x;
	cin >> x;

	if (x == 8) 
	{
		bool kt = 1;

		while (kt)
		{
			Convexpoly convexpoly; // local var khong dung o ngoai vong while duoc

			if (convexpoly.IsConvex()) 
			{
				cout << "day la da giac loi\n";
				kt = 0;



			}
			else 
			{
				cout << "day la da giac lom, moi nhap lai\n";
			}
			
		}

	}
	else if(x>0 && x<8)
	{
		switch (x)
		{
			case 1:
			{
				Point point; 
				point.input(); 
				break;
			};
			case 2:
			{
				Segment segment; //da co constructor khong can funtion input
				
				break;
			};
			case 3:
			{
				Line line; 
				line.input(); 
				break;
			};
			case 4:
			{
				Vector vector; 
				vector.input();
				break;
			};
			case 5:
			{
				Triangle triangle; 
				triangle.input(); 
				if (triangle.IsTriangle(triangle.A, triangle.B, triangle.C))
				{
					cout << "tam giac hop le";
				}
				else
				{
					cout << "tam giac khong hop le";
				}

				break;
			};
			case 6:
			{
				Reangle reangle; 
				reangle.input(); 
				break;
			};
			case 7:
			{
				Circle circle; 
				circle.input(); 
				break;
			};

		}
	}
	else { cout << "khong co doi tuong nay"; }
	

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
