#pragma once

class GeometrVector {
private:
    float x, y;
public:
    GeometrVector() {
        this->x = 0.0;
        this->y = 0.0;
    }

    GeometrVector(float x, float y) {
        this->x = x;
        this->y = y;
    }
    void setX(float x) {
        this->x = x;
    }
    void setY(float y) {
        this->y = y;
    }
    float getX() const {
        return x;
    }
    float getY() const {
        return y;
    }
    // оператор сложения двух векторов
    GeometrVector operator+(const GeometrVector& other) const {
        float newX = x + other.x;
        float newY = y + other.y;
        return GeometrVector(newX, newY);
    }
    // оператор вычитания двух векторов
    GeometrVector operator-(const GeometrVector& other) const {
        float newX = x - other.x;
        float newY = y - other.y;
        return GeometrVector(newX, newY);
    }

    bool operator==(const GeometrVector& other) const {
        return x == other.x && y == other.y;
    }
};

class Entity {
private:
    GeometrVector position;
    GeometrVector velocity;
    float size;
    float light;
public:
    Entity(GeometrVector pos, float size, float light, GeometrVector v) {
        this->position = pos;
        this->size = size;
        this->light = light;
        this->velocity = v;
    }

    void setVelocity(GeometrVector v) {
        this->velocity = v;
    }

    void setPosition(GeometrVector pos) {
        this->position = pos;
    }

    void setSize(float size) {
        this->size = size;
    }

    void setLight(float light) {
        this->light = light;
    }

    float getSize() const {
        return size;
    }

    float getLight() const {
        return light;
    }

    GeometrVector getPosition() const {
        return position;
    }

    GeometrVector getVelocity() const {
        return this->velocity;
    }
};