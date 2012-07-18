#ifndef _TCPSTATE_H_
#define _TCPSTATE_H_

#include <iostream>

#include "TCPConnection.h"
#include "TCPOctetStream.h"

using namespace std;

struct MyStruct
{
	union {
		struct
		{
			unsigned char ch1 : 4;
			unsigned char ch2 : 4;
		};
		unsigned char ch;
	};
};

class TCPState
{
public:
	virtual void Transmit(TCPConnection*, TCPOctetStream*);
	virtual void ActiveOpen(TCPConnection*);
	virtual void PassiveOpen(TCPConnection*);
	virtual void Close(TCPConnection*);
	virtual void Synchronize(TCPConnection*);
	virtual void Acknowledge(TCPConnection*);
	virtual void Send(TCPConnection*);
protected:
	void ChangeState(TCPConnection*, TCPState*);
};

class TCPEstablished : public TCPState
{
public:
	static TCPState* Instance() { return new TCPEstablished(); }
	virtual void Transmit(TCPConnection*, TCPOctetStream*);
	virtual void Close(TCPConnection*);
};

class TCPListen : public TCPState
{
public:
	static TCPState* Instance() { return new TCPListen(); }
	virtual void Send(TCPConnection*);
	// ...
};

class TCPClosed : public TCPState
{
public:
	TCPClosed(){ cout << "TCP in Closed state." << endl; }
	static TCPState* Instance() { return new TCPClosed(); }
	virtual void ActiveOpen(TCPConnection*);
	virtual void PassiveOpen(TCPConnection*);
	// ...
};

//////////////////////////////////////////////////////////////////////////////////
// if defined in header file, must declared as inline
// or will get redefined error in linking stage.
//////////////////////////////////////////////////////////////////////////////////

inline void TCPClosed::ActiveOpen(TCPConnection* t)
{
	// send SYN, receive SYN, ACK, etc.
	ChangeState(t, TCPEstablished::Instance());
}

inline void TCPClosed::PassiveOpen(TCPConnection* t)
{
	ChangeState(t, TCPListen::Instance());
}

/////////////////////////////////////////////////////////////////////////////////

inline void TCPEstablished::Close(TCPConnection* t)
{
	// send FIN, receive ACK of FIN
	ChangeState(t, TCPListen::Instance());
}

inline void TCPEstablished::Transmit(TCPConnection* t, TCPOctetStream* o)
{
	t->ProcessOctet(o);
}

/////////////////////////////////////////////////////////////////////////////////

inline void TCPListen::Send(TCPConnection* t)
{
	// send SYN, receive SYN, ACK, etc.
	ChangeState(t, TCPEstablished::Instance());
}

/////////////////////////////////////////////////////////////////////////////////

#endif