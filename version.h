#ifndef VERSION_H
#define VERSION_H
#include "repository.h"

extern const char git_version_string[];
extern const char git_built_from_commit_string[];

const char *git_user_agent(void);
const char *git_user_agent_sanitized(void);

/*
  Try to get information about the system using uname(2).
  Return -1 and put an error message into 'buf' in case of uname()
  error. Return 0 and put uname info into 'buf' otherwise.
*/
int get_uname_info(struct strbuf *buf, int is_bug_report);

const char *os_version(void);
const char *os_version_sanitized(void);
int advertise_os_version(struct repository *r);

#endif /* VERSION_H */
