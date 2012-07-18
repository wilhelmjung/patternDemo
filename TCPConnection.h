#ifndef _TCPCONNECTION_H_
#define _TCPCONNECTION_H_
#include "TCPOctetStream.h"

class TCPConnection {

public:
	TCPConnection();
	~TCPConnection();
	void ActiveOpen();
	void PassiveOpen();
	void Close();
	void Send();
	void Acknowledge();
	void Synchronize();
	void ProcessOctet(TCPOctetStream*);

private:
	friend class TCPState;
	void ChangeState(TCPState*);

private:
	TCPState* _state;
};

#endif