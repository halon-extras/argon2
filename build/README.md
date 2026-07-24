# Build instructions

```
export HALON_REPO_USER=exampleuser
export HALON_REPO_PASS=examplepass
docker compose -p halon-extras-argon2 --profile all up --build
docker compose -p halon-extras-argon2 down --rmi local
```
