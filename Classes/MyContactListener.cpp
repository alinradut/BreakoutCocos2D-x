//
//  MyContactListener.cpp
//  BreakoutCocos2D-x
//
//  Created by Clawoo on 9/16/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "MyContactListener.h"

MyContactListener::MyContactListener() : _contacts() 
{
}

MyContactListener::~MyContactListener() 
{
}

void MyContactListener::BeginContact(b2Contact* contact) 
{
    // We need to copy out the data because the b2Contact passed in
    // is reused.
    MyContact myContact = { contact->GetFixtureA(), contact->GetFixtureB() };
    _contacts.push_back(myContact);
}

void MyContactListener::EndContact(b2Contact* contact) 
{
    MyContact myContact = { contact->GetFixtureA(), contact->GetFixtureB() };
    std::vector<MyContact>::iterator pos;
    pos = std::find(_contacts.begin(), _contacts.end(), myContact);
    if (pos != _contacts.end()) 
    {
        _contacts.erase(pos);
    }
}

void MyContactListener::PreSolve(b2Contact* contact, 
                                 const b2Manifold* oldManifold) 
{
}

void MyContactListener::PostSolve(b2Contact* contact, 
                                  const b2ContactImpulse* impulse) 
{
}