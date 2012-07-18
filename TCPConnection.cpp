#include <iostream>
#include "TCPConnection.h"
#include "TCPState.h"

using namespace std;

TCPConnection::TCPConnection()
{
	cout << "TCP Connection Created." << endl;
	_state = TCPClosed::Instance();
}

TCPConnection::~TCPConnection()
{
	cout << "Connection Abort." << endl;
}

////////////////////////////////////////////////////////////////////

void TCPConnection::ChangeState (TCPState* s)
{
	_state = s;
}

void TCPConnection::ActiveOpen()
{
	_state->ActiveOpen(this);
}

void TCPConnection::PassiveOpen()
{
	_state->PassiveOpen(this);
}

void TCPConnection::Close()
{
	_state->Close(this);
}

void TCPConnection::Acknowledge()
{
	_state->Acknowledge(this);
}

void TCPConnection::Synchronize()
{
	_state->Synchronize(this);
}

void TCPConnection::ProcessOctet(TCPOctetStream *os)
{
	cout << "Process octet stream." << endl;
}
