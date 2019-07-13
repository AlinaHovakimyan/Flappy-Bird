#ifndef USERITERACTIONDELEGATE_H
#define USERITERACTIONDELEGATE_H

enum UserActionKey
{
	UserActionKeySpace,
	UserActionKeyEscape,
	UserActionKeyPause,
};

class UserIteractionDelegate
{
public:
	virtual void did_press_key(UserActionKey userActionKey) = 0;
};

#endif // !USERITERACTIONDELEGATE_H
