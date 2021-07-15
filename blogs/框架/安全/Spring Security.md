Spring Security提供了声明式的安全访问控制解决方案，对访问权限进行谁和授权，它基于Spring AOP和Servlet过滤器，提供了安全性方面的全面解决方案。

除了常规的认证和授权外，它还提供了ACLS，LDAP、JAAS，CAS等高级特性以满足复杂环境下的安全需求。

1、核心概念

Principle:

代表用户的对象Principle(User),不仅指人类，还包括一切可以用于验证的设备。

Authority:

代表用户的角色 （Role),每个用户都应该有一种角色，如管理员或者是会员。

Permission:

代表授权，复杂的应环境需要对角色的权限进行表述。





