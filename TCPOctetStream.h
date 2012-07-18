#ifndef _TCPOCTETSTREAM_H_
#define _TCPOCTETSTREAM_H_

class TCPOctetStream
{
public:
	TCPOctetStream(){ octets = new unsigned char[8]; }
	~TCPOctetStream(){ delete[] octets; }
	unsigned char* octets;
};

#endif