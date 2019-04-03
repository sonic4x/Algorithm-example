#pragma once

template<typename T>
class MakeSealed
{
	friend T;
private:
	MakeSealed() {}
	~MakeSealed() {}
};

class SealedClass: virtual public MakeSealed<SealedClass>
{
public:
	SealedClass() {}
	~SealedClass() {}
};


class SubClass :public SealedClass  
{
public:
	//compile err. Since SealedClass is virtual derived, 
	//the following c'tor will directly invoke grandparent c'tor which is not accessible.

	//SubClass() {}
	//~SubClass() {}
};

