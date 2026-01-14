# argon2 hashing functions

This plugin is a wrapper around [libargon2](https://github.com/P-H-C/phc-winner-argon2).

## Installation

Follow the [instructions](https://docs.halon.io/manual/comp_install.html#installation) in our manual to add our package repository and then run the below command.

### Ubuntu

```
apt-get install halon-extras-argon2
```

### RHEL

```
yum install halon-extras-argon2
```

## Exported functions

These functions needs to be [imported](https://docs.halon.io/hsl/structures.html#import) from the `extras://argon2` module path.

### argon2[d|i|id]_verify(encoded, pwd)

Return ``boolean`` if password matches hash.

**Params**

- encoded `string` - The encoded hash
- pwd `string` - The password to verify

**Returns**

Return ``boolean`` if password matches hash.

**Example**

```
import { argon2d_verify } from "extras://argon2";
echo argon2d_verify(''$argon2d$v=19$m=16,t=2,p=1$Z0E4ODUyckw1SmFWQ2hqbA$i4VZhbsITfwLIRPfkUqaFQ'', "hello");
```
