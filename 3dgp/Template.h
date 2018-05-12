#ifndef _TEMPLATE_H_
#define _TEMPLATE_H_

template <typename T>
class Singleton
{
public:

	static T* getInstance() {
		static T instance;
		return &instance;
	};

};

#endif // !_TEMPLATE_H_
