#ifndef BRAIN_H
#define BRAIN_H

class Brain
{
public:
	Brain(void);
	~Brain(void);
	bool selectCard(CardSet *field, CardSet *in, CardSet *out);
private:
};

#endif
