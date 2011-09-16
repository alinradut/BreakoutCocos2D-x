//
//  MyContactListener.h
//  BreakoutCocos2D-x
//
//  Created by Clawoo on 9/16/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//
#ifndef __MY_CONTACT_LISTENER_H__
#define __MY_CONTACT_LISTENER_H__

#include "Box2D.h"
#include <vector>

struct MyContact {
    b2Fixture *fixtureA;
    b2Fixture *fixtureB;
    bool operator==(const MyContact& other) const
    {
        return (fixtureA == other.fixtureA) && (fixtureB == other.fixtureB);
    }
};


class MyContactListener : public b2ContactListener {
public:
    std::vector<MyContact> _contacts;
    
    MyContactListener();
    ~MyContactListener();
    
    virtual void BeginContact(b2Contact* contact);
    virtual void EndContact(b2Contact* contact);
    virtual void PreSolve(b2Contact* contact, const b2Manifold* oldManifold);    
    virtual void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse);
    
private:
};

#endif // __MY_CONTACT_LISTENER_H__