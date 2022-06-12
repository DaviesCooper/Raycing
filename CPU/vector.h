#ifndef VECTOR
#define VECTOR



struct Vector{
    public:

        double x, y, z;

        Vector operator - (Vector other){
            return Vector(x - other.x, y - other.y, z - other.z);
        }

        double dot(Vector other){
            return x * other.x + y * other.y + z * other.z;
        }

        Vector operator * (double val){
            return Vector(x * val, y * val, z * val);
        }

        Vector operator /(double val){
            return Vector(x / val, y / val, z / val);
        }

        Vector()
        {
            x = y = z = 0;
        }

        explicit Vector(double _x, double _y, double _z){
            x = _x;
            y = _y;
            z = _z;
        }
};

#endif