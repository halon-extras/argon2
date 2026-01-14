# Build instructions

```
export HALON_REPO_USER=exampleuser
export HALON_REPO_PASS=examplepass
docker compose -p halon-extras-argon2 up --build
docker compose -p halon-extras-argon2 down --rmi local
```
