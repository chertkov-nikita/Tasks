#include "application.h"

#include <iostream>

using namespace std;

TApplication::TApplication()
{

}

void TApplication:: exec(){

    int ch;
    int a, b, c, alpha, beta, r;

    while(true) {       
        cout << endl;
        cout << "1)Triangle" <<endl;
        cout << "2)Isosceles triangle" <<endl;
        cout << "3)Equilateral triangle" <<endl;
        cout << "4)Quadrangle" <<endl;
        cout << "5)Parallelogram" <<endl;
        cout << "6)Rectangle" <<endl;
        cout << "7)Rhombus" <<endl;
        cout << "8)Square" <<endl;
        cout << "9)Circle" <<endl;
        cout << "0 - Exit" <<endl;

        cin >> ch;

        switch(ch) {
        case 0 : return;
        case 1: {
            cout << "side a = ";
            cin >> a;
            cout << "side b = ";
            cin >> b;
            cout << "angle = ";
            cin >> alpha;
            TTriangle *tr = new TTriangle(a, b, alpha);
            cout << "area: " << tr->area() << endl;
            cout << "perimetr: " << tr->perimetr() << endl;
            break;
        }
        case 2: {
            cout << "side a = ";
            cin >> a;
            cout << "angle = ";
            cin >> alpha;
            TIsosceles_triangle *tr = new TIsosceles_triangle(a, alpha);
            cout << "area: " << tr->area() << endl;
            cout << "perimetr: " << tr->perimetr() << endl;
            break;
        }
        case 3: {
            cout << "side a = ";
            cin >> a;
            TEquilateral_triangle *tr = new TEquilateral_triangle(a);
            cout << "area: " << tr->area() << endl;
            cout << "perimetr: " << tr->perimetr() << endl;
            break;
        }
        case 4: {
            cout << "side a = ";
            cin >> a;
            cout << "side b = ";
            cin >> b;
            cout << "side c = ";
            cin >> c;
            cout << "A angle = ";
            cin >> alpha;
            cout << "B angle = ";
            cin >> beta;
            TQuadrangle *q = new TQuadrangle(a, b, c, alpha, beta);
            cout << "area: " << q->area() << endl;
            cout << "perimetr: " << q->perimetr() << endl;
            break;
        }
        case 5: {
            cout << "side a = ";
            cin >> a;
            cout << "side b = ";
            cin >> b;
            cout << "angle = ";
            cin >> alpha;
            TParallelogram *p = new TParallelogram(a, b, alpha);
            cout << "area: " << p->area() << endl;
            cout << "perimetr: " << p->perimetr() << endl;
            break;
        }
        case 6: {
            cout << "side a = ";
            cin >> a;
            cout << "side b = ";
            cin >> b;
            TRectangle *rect = new TRectangle(a, b);
            cout << "area: " << rect->area() << endl;
            cout << "perimetr: " << rect->perimetr() << endl;
            break;
        }
        case 7: {
            cout << "side = ";
            cin >> a;
            cout << "angle = ";
            cin >> alpha;
            TRhombus *rh = new TRhombus(a, alpha);
            cout << "area: " << rh->area() << endl;
            cout << "perimetr: " << rh->perimetr() << endl;
            break;
        }
        case 8: {
            cout << "side = ";
            cin >> a;
            TSquare *sq = new TSquare(a);
            cout << "area: " << sq->area() << endl;
            cout << "perimetr: " << sq->perimetr() << endl;
            break;
        }
        case 9: {
            cout << "side r = ";
            cin >> r;
            TCircle *c = new TCircle(r);
            cout << "area: " << c->area() << endl;
            cout << "perimetr: " << c->perimetr() << endl;
            break;
        }
        default:
            break;
        }
    }
}
