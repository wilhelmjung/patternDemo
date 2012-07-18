#include "TCPState.h"
#include "TCPConnection.h"
#include "TCPOctetStream.h"

void TCPState::Transmit(TCPConnection* t, TCPOctetStream* o)
{
}

void TCPState::ActiveOpen(TCPConnection* t)
{
}

void TCPState::PassiveOpen(TCPConnection* t)
{
}

void TCPState::Close(TCPConnection* t)
{
}

void TCPState::Synchronize(TCPConnection* t)
{
}

void TCPState::Acknowledge(TCPConnection* t)
{
}

void TCPState::Send(TCPConnection* t)
{
}

void TCPState::ChangeState(TCPConnection* t, TCPState* s)
{
	t->ChangeState(s);
}