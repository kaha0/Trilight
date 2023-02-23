#pragma once
#pragma warning( disable : 4482 )

#include<Box2D.h>
#include<Object.h>

class JointDefWrapper
{
protected:
	JointDefWrapper()
	{
		type = b2JointType::e_unknownJoint;
	}

public:
	b2JointType type;

	static JointDefWrapper * FromJoint(b2Joint * j)//;  // má tohle vùbec smysl? pøed vytváøením wrapperu stejnì musim kouknout na (o1+o2)->reconstruct
	{
		return NULL;
	}
};

// pro všechny jointy, který budu potøebovat, udìlat specializovaný wrappery
class RevoluteJointDefWrapper : public JointDefWrapper
{
public:
	b2RevoluteJointDef rjd;
	Object * object1;
	Object * object2;

	RevoluteJointDefWrapper()
	{
		type = b2JointType::e_revoluteJoint;
		object1 = NULL;
		object2 = NULL;
	}

	RevoluteJointDefWrapper(b2RevoluteJoint * rj)
	{
		type = b2JointType::e_revoluteJoint;
		object1 = (Object *)rj->GetBodyA()->GetUserData();
		object2 = (Object *)rj->GetBodyB()->GetUserData();

		rjd.collideConnected = rj->GetCollideConnected();
		rjd.enableLimit = rj->IsLimitEnabled();
		rjd.enableMotor = rj->IsMotorEnabled();
		rjd.localAnchorA = rj->GetLocalAnchorA();
		rjd.localAnchorB = rj->GetLocalAnchorB();
		rjd.lowerAngle = rj->GetLowerLimit();
		rjd.maxMotorTorque = rj->GetMaxMotorTorque();
		rjd.motorSpeed = rj->GetMotorSpeed();
		rjd.referenceAngle = rj->GetJointAngle();
		rjd.upperAngle = rj->GetUpperLimit();
	}

	b2RevoluteJointDef ToDef()
	{
		b2RevoluteJointDef r = rjd;
		if (object1) r.bodyA = object1->body;
		if (object2) r.bodyB = object2->body;
		return r;
	}
};

class DistanceJointDefWrapper : public JointDefWrapper
{
public:
	b2DistanceJointDef djd;
	Object * object1;
	Object * object2;

	DistanceJointDefWrapper()
	{
		type = b2JointType::e_distanceJoint;
		object1 = NULL;
		object2 = NULL;
	}

	DistanceJointDefWrapper(b2DistanceJoint * dj)
	{
		type = b2JointType::e_distanceJoint;
		object1 = (Object *)dj->GetBodyA()->GetUserData();
		object2 = (Object *)dj->GetBodyB()->GetUserData();

		djd.collideConnected = dj->GetCollideConnected();
		djd.dampingRatio = dj->GetDampingRatio();
		djd.frequencyHz = dj->GetFrequency();
		djd.length = dj->GetLength();
		djd.localAnchorA = dj->GetLocalAnchorA();
		djd.localAnchorB = dj->GetLocalAnchorB();
	}

	b2DistanceJointDef ToDef()
	{
		b2DistanceJointDef r = djd;
		if (object1) r.bodyA = object1->body;
		if (object2) r.bodyB = object2->body;
		return r;
	}
};

class PulleyJointDefWrapper : public JointDefWrapper
{
public:
	b2PulleyJointDef pjd;
	Object * object1;
	Object * object2;

	PulleyJointDefWrapper()
	{
		type = b2JointType::e_pulleyJoint;
		object1 = NULL;
		object2 = NULL;
	}

	PulleyJointDefWrapper(b2PulleyJoint * pj)
	{
		type = b2JointType::e_pulleyJoint;
		object1 = (Object *)pj->GetBodyA()->GetUserData();
		object2 = (Object *)pj->GetBodyB()->GetUserData();

		pjd.collideConnected = pj->GetCollideConnected();
		pjd.groundAnchorA = pj->GetGroundAnchorA();
		pjd.groundAnchorB = pj->GetGroundAnchorB();
		pjd.lengthA = pj->GetLengthA();
		pjd.lengthB = pj->GetLengthB();
		pjd.localAnchorA = object1->body->GetLocalPoint(pj->GetAnchorA());
		pjd.localAnchorB = object2->body->GetLocalPoint(pj->GetAnchorB());
		pjd.ratio = pj->GetRatio();
	}

	b2PulleyJointDef ToDef()
	{
		b2PulleyJointDef r = pjd;
		if (object1) r.bodyA = object1->body;
		if (object2) r.bodyB = object2->body;
		return r;
	}
};