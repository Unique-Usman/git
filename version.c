#include "git-compat-util.h"
#include "version.h"
#include "strbuf.h"

const char git_version_string[] = GIT_VERSION;
const char git_built_from_commit_string[] = GIT_BUILT_FROM_COMMIT;

static void strbuf_sanitize(struct strbuf *buf)
{
	strbuf_trim(buf);
	for (size_t i = 0; i < buf->len; i++) {
		if (buf->buf[i] <= 32 || buf->buf[i] >= 127)
			buf->buf[i] = '.';
	}
}

const char *git_user_agent(void)
{
	static const char *agent = NULL;

	if (!agent) {
		agent = getenv("GIT_USER_AGENT");
		if (!agent)
			agent = GIT_USER_AGENT;
	}

	return agent;
}

const char *git_user_agent_sanitized(void)
{
	static const char *agent = NULL;

	if (!agent) {
		struct strbuf buf = STRBUF_INIT;

		strbuf_addstr(&buf, git_user_agent());
		strbuf_sanitize(&buf);
		agent = strbuf_detach(&buf, NULL);
	}

	return agent;
}
