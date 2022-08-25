#include <iostream>
using namespace std;

class Area
{
    float side;
    float length, breadth;
    float radius;

public:
    Area(float a = 1, float l = 1, float b = 1, float r = 1)
    {
        this->side = a;
        this->length = l;
        this->breadth = b;
        this->radius = r;
    }

    friend inline float square(Area ar);
    friend inline float rect(Area ar);
    friend inline float circle(Area ar);
};

inline float square(Area ar)
{
    return (ar.side * ar.side);
}

inline float rect(Area ar)
{
    return (ar.length * ar.breadth);
}

inline float circle(Area ar)
{
    return (ar.radius * ar.radius * 3.1415f);
}

class Volume
{
    float height;

public:
    Volume(float h = 1)
    {
        this->height = h;
    }

    inline float cube(Area ar)
    {
        return (this->height * square(ar));
    }
    inline float cuboid(Area ar)
    {
        return (this->height * rect(ar));
    }
    inline float sphere(Area ar)
    {
        return (this->height * 4 / 6.0 * circle(ar));
    }
    void comp_cube(Area ar1, Area ar2, Volume vol1, Volume vol2);
    void comp_cuboid(Area ar1, Area ar2, Volume vol1, Volume vol2);
    void comp_sphere(Area ar1, Area ar2, Volume vol1, Volume vol2);
};

void Volume::comp_cube(Area ar1, Area ar2, Volume vol1, Volume vol2)
{
    if (vol1.cube(ar1) > vol2.cube(ar2))
        cout << "Cube 1 is greater than Cube 2" << endl;
    else if (vol1.cube(ar1) < vol2.cube(ar2))
        cout << "Cube 1 is less than Cube 2" << endl;
    else
        cout << "Cube 1 is equal to Cube 2" << endl;
}

void Volume::comp_cuboid(Area ar1, Area ar2, Volume vol1, Volume vol2)
{
    if (vol1.cuboid(ar1) > vol2.cuboid(ar2))
        cout << "Cuboid 1 is greater than Cuboid 2" << endl;
    else if (vol1.cuboid(ar1) < vol2.cuboid(ar2))
        cout << "Cuboid 1 is less than Cuboid 2" << endl;
    else
        cout << "Cuboid 1 is equal to Cuboid 2" << endl;
}

void Volume::comp_sphere(Area ar1, Area ar2, Volume vol1, Volume vol2)
{
    if (vol1.sphere(ar1) > vol2.sphere(ar2))
        cout << "Sphere 1 is greater than Sphere 2" << endl;
    else if (vol1.sphere(ar1) < vol2.sphere(ar2))
        cout << "Sphere 1 is less than Sphere 2" << endl;
    else
        cout << "Sphere 1 is equal to Sphere 2" << endl;
}

int main()
{
    int choice = 0;
    cout << "1. Area of a Square" << endl;
    cout << "2. Area of a Rectangle" << endl;
    cout << "3. Area of a Circle" << endl;
    cout << "4. Volume of a Cube" << endl;
    cout << "5. Volume of a Cuboid" << endl;
    cout << "6. Volume of a Sphere" << endl;
    cout << "7. Compare Cube" << endl;
    cout << "8. Compare Cuboid" << endl;
    cout << "9. Compare Sphere" << endl;
    cout << "10. Exit" << endl;

    while (choice != 10)
    {
        cout << "\nEnter the choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            float a;
            cout << "Square" << endl;
            cout << "\tSide: ";
            cin >> a;
            Area sq_ar(a);
            cout << "\tArea: " << square(sq_ar) << endl;
            break;
        }
        case 2:
        {
            float l, b;
            cout << "Rectangle" << endl;
            cout << "\tLength and Breadth: ";
            cin >> l >> b;
            Area rect_ar(1, l, b);
            cout << "\tArea: " << rect(rect_ar) << endl;
            break;
        }
        case 3:
        {
            float r;
            cout << "Circle" << endl;
            cout << "\tRadius: ";
            cin >> r;
            Area cr_ar(1, 1, 1, r);
            cout << "\tArea: " << circle(cr_ar) << endl;
            break;
        }
        case 4:
        {
            float a;
            cout << "Cube" << endl;
            cout << "\tSide: ";
            cin >> a;
            Area sq_ar(a);
            Volume sq_vol(a);
            cout << "\tVolume: " << sq_vol.cube(sq_ar) << endl;
            break;
        }
        case 5:
        {
            float l, b, h;
            cout << "Rectangle" << endl;
            cout << "\tLength, Breadth and Height: ";
            cin >> l >> b >> h;
            Area rect_ar(1, l, b);
            Volume rect_vol(h);
            cout << "\tVolume: " << rect_vol.cuboid(rect_ar) << endl;
            break;
        }
        case 6:
        {
            float r;
            cout << "Sphere" << endl;
            cout << "\tRadius: ";
            cin >> r;
            Area cr_ar(1, 1, 1, r);
            Volume cr_vol(2 * r);
            cout << "\tVolume: " << cr_vol.sphere(cr_ar) << endl;
            break;
        }
        case 7:
        {
            float a1, a2;
            cout << "Cube 1" << endl;
            cout << "\tSide: ";
            cin >> a1;
            Area sq_ar1(a1);
            Volume sq_vol1(a1);
            cout << "Cube 2" << endl;
            cout << "\tSide: ";
            cin >> a2;
            Area sq_ar2(a2);
            Volume sq_vol2(a2);
            sq_vol1.comp_cube(sq_ar1, sq_ar2, sq_vol1, sq_vol2);
            break;
        }
        case 8:
        {
            float l1, l2, b1, b2, h1, h2;
            cout << "Cuboid 1" << endl;
            cout << "\tLength, Breadth and Height: ";
            cin >> l1 >> b1 >> h1;
            Area rect_ar1(1, l1, b1);
            Volume rect_vol1(h1);
            cout << "Cuboid 2" << endl;
            cout << "\tLength, Breadth and Height: ";
            cin >> l2 >> b2 >> h2;
            Area rect_ar2(1, l2, b2);
            Volume rect_vol2(h2);
            rect_vol1.comp_cuboid(rect_ar1, rect_ar2, rect_vol1, rect_vol2);
            break;
        }
        case 9:
        {
            float r1, r2;
            cout << "Sphere 1" << endl;
            cout << "\tRadius: ";
            cin >> r1;
            Area cr_ar1(1, 1, 1, r1);
            Volume cr_vol1(2 * r1);
            cout << "Sphere 2" << endl;
            cout << "\tRadius: ";
            cin >> r2;
            Area cr_ar2(1, 1, 1, r2);
            Volume cr_vol2(2 * r2);
            cr_vol1.comp_sphere(cr_ar1, cr_ar2, cr_vol1, cr_vol2);
            break;
        }
        case 10:
            break;
        default:
            cout << "Invalid Choice" << endl;
            break;
        }
    }

    return 0;
}