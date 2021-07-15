## 一、基础知识：

### 权限管理：

权限管理实现对用户访问系统的控制，按照安全规则或者安全策略**控制用户可以访问而且只能访问自己被授权的资源**。

权限管理分为：

- 用户认证

- 用户授权



#### 1、用户认证

用户认证，用户去访问系统，系统要验证用户身份的合法性

用户认证的流程：

- 判断该用户能否不认证就能访问【登陆界面，首页】

- 如果该资源需要认证后才能访问，那么判断该用户是否认证了

- 如果还没有认证，那么需要返回到登陆界面进行认证

- 认证通过后才能访问资源

  

##### **概念抽取：**

------

**subject (主体) :**

 可以是程序，也可以是用户，当subject要去访问系统的资源时，系统需要对subject进行身份认证

**principal (身份信息)：**

一个主体含有多个身份信息，但是都有一个主身份信息（primary principal ) 【身份证，学生证都是我们的身份信息】

**credential （凭证信息）：** 

可以是密码，也可以是证书或者指纹



总结：在进行用户认证时需要提供身份信息和凭证信息



#### 2、用户授权

用户授权，简单理解为访问控制，在用户认证通过后，系统对用户访问的资源进行控制，用户具有资源的访问权限方可访问



用户授权的流程：

- 用户认证

- 用户访问资源，系统去判断该用户是否有权限去操作该资源
- 如果无权限，但不能访问



授权过程可以理解为：主体认证之后，系统进行访问控制



subject必须具备资源的访问权限才可以访问该资源



**权限/许可（permission):**

针对资源的权限或许可，subject具有permission访问资源，权限例如：用户添加，用户修改，商品删除



资源分为两种：

- 类型：系统的用户信息就是资源类型，相当于java类
- 实例：系统中的id为001的用户就是资源实例，相当于new的java对象



#### 3、权限管理模型：



主体（账号、密码）

资源（资源名称、访问地址）

权限（权限名称、资源id)

角色（角色名称）

角色和权限关系（角色id,权限id)

主体和角色关系（主体id,角色id）

![image-20201224110509942](https://raw.githubusercontent.com/znsfox/PicGo/master/img/20201224110510.png)

一般情况下将其合并为一张权限表：

![image-20201224110626979](https://raw.githubusercontent.com/znsfox/PicGo/master/img/20201224110627.png)

#### 4、分配权限 

通常给用户分配资源权限需要将权限信息持久化，比如存储在关系数据库中



- 基于角色的控制访问

  **RBAC(role  based  access  control)，基于角色的访问控制。**

```
//如果该user是部门经理则可以访问if中的代码
if(user.hasRole('部门经理')){
    //系统资源内容
    //用户报表查看
}
```

基于角色的访问控制不利于系统维护



- 基于资源的访问控制

**RBAC(Resource  based  access  control)，基于资源的访问控制。**

```
对资源的访问需要具有permission权限，代码可以写为：

if(user.hasPermission ('用户报表查看（权限标识符）')){
    //系统资源内容
    //用户报表查看
}
```

**建议使用基于资源的访问控制实现权限管理**。



## 二、粗粒度和细粒度权限：

细粒度权限管理：对资源实例的权限管理。

资源实例就是资源类型的具体化。

**细粒度权限管理就是数据级别的权限管理**

粗粒度权限管理比如：超级管理员可以访问户添加页面、用户信息等全部页面。部门管理员可以访问用户信息页面包括 页面中所有按钮。

### 实现粗粒度权限管理：

可以将**权限管理的代码抽取出来在系统架构级别统一管理，**比如通过SpringMVc的拦截器实现授权

#### 1、基于URL拦截

对于web系统，通过filter过滤器实现url拦截，也可以springMVC的拦截器实现基于url的拦截

#### 2、使用权限管理框架实现

例如shiro



## Shiro介绍

### 架构：

- <img src="https://raw.githubusercontent.com/znsfox/PicGo/master/img/20201224141713.png" alt="image-20201224141712805" style="zoom: 67%;" />
- **securityManager**:

安全管理器，主体通过认证和授权都是通过securityManager进行。

- **authenticator**:

认证器，主体通过认证，最终通过authenticator进行的。

- **sessionManager**:

web容器中一般是用web容器对session进行管理，shiro也提供了一套session管理的方式

- **sessionDao**:

通过sessionDao管理session数据，针对个性化的session存储需要使用sessionDao.

- **cacheManager**:

缓存处理器，主要对session和授权数据进行缓存，比如将授权数据通过cacheManager进行缓存管理，和ehcache整合对缓存数据进行管理。

- **realm**:

域，领域，相当于数据源，通过realm存取认证，授权相关数据 



- **cryptography**:

密码管理，提供了一套加密解密的组件 ，方便开发 ，比如提供常用的散列、加/解密等功能

比如md5散列算法



1、shiro认证流程：

- 构造SecurityManager环境
- Subject.login()提交认证
- SecurityManager.login()执行认证
- Authenticator执行认证
- realm执行认证





登陆认证实现：

在shrio中，最终是通过realm来获取应用程序中的用户、角色及权限信息的。

通常情况下，在realm中，会直接从我们的数据源中获取Shiro需要的验证信息。

可以说，Realm中是专用于安全框架的Dao。





### 应用：

权限配置的步骤为：

先拿到用户信息，然后根据用户信息查询到角色，再通过角色查询到权限SimplerAuthorization.





### Shiro内置过滤器：

logout : 退出

noSessionCreation: 不创建session

perms:  许可验证

port： (端口验证）

rest:

roles:权限验证

ssl:

认证过滤器：

- anno(匿名）:不认证也可以访问
- authcBasic ：http基本验证
- authc（身份验证）： 必须认证后才能访问
- user

授权过滤器：

- perms:指定资源需要哪些权限才可以访问
- Roles
- ssl
- rest 
- port



#### User和authc不同

当应用开启了RememberMe时，用户下次访问时可以是一个User,但不会是authc,因为authc是需要重新认证的

User表示用户不一定已通过谁，只要是被shiro记住过登陆状态的用户就可以正常发起请求，比如RememberMe



下面举几个例子介绍一下（注意URLPattern写的是两颗星，这样才能实现任意层次的全匹配）

1. `/admin/**=anon` ：无参，表示可匿名访问
2. `/admin/user/**=authc` ：无参，表示需要认证才能访问
3. `/admin/user/**=authcBasic` ：无参，表示需要httpBasic认证才能访问
4. `/admin/user/**=ssl` ：无参，表示需要安全的URL请求，协议为https
5. `/home=user` ：表示用户不一定需要通过认证，只要曾被 Shiro 记住过登录状态就可以正常发起 /home 请求
6. `/edit=authc,perms[admin:edit]`：表示用户必需已通过认证，并拥有 admin:edit 权限才可以正常发起 /edit 请求
7. `/admin=authc,roles[admin]` ：表示用户必需已通过认证，并拥有 admin 角色才可以正常发起 /admin 请求
8. `/admin/user/**=port[8081]` ：当请求的URL端口不是8081时，跳转到schemal://serverName:8081?queryString
9. `/admin/user/**=rest[user]` ：根据请求方式来识别，相当于 `/admins/user/**=perms[user:get]或perms[user:post]` 等等
10. `/admin**=roles["admin,guest"]` ：允许多个参数（逗号分隔），此时要全部通过才算通过，相当于hasAllRoles()
11. `/admin**=perms["user:add:*,user:del:*"]`：允许多个参数（逗号分隔），此时要全部通过才算通过，相当于isPermitedAll()





Sort sort = Sort.by(Sort.Order.desc("create_date"));
Pageable pageable =PageRequest.of(Integer.parseInt(page), Integer.parseInt(size), sort);





# second:



用户认证，

认证之后的授权



## shiro 配置文件

ini文件



## 步骤：

1、创建安全管理器对象

2、给安全处理器设置realm,提供认证和制授权

### Realm:

##### 认证

AuthenticatingRealm **认证realm**  doGetAuthenticationInfo

##### 授权

AuthorizingRealm	授权realm	doGetAuthorizationInfo





#### 自定义realm

在里面获得principal

3、SecurityUtils, 给安全工具类设置安全管理器

4、关键对象，subject主体

5、创建令牌





### MD5

作用：一般用来加密 或者 签名（校验和）

特点：MD5算法不可逆，如果内容一致，无论执行多少次，其结果始终一致

生成结果：始终是一个16进制，32位长度的字符串

md5Hash





### 授权方式：

授权，访问控制

**权限离开资源没有任何意义**

- role-based
- resource-based



### 权限字符串：

规则：`资源标识符：操作：资源实例标识符`







git remote add origin https://github.com/wu347771769/learngit.git



### springbooy-shiro:

#### ShiroConfig

1.创建ShiroFilter

2.创建安全处理器

3.创建自定义realm





<img src="../../../../../AppData/Roaming/Typora/typora-user-images/image-20210331095842179.png" alt="image-20210331095842179" style="zoom:50%;" />





<img src="https://raw.githubusercontent.com/znsfox/PicGo/master/img/20210331100133.png" alt="image-20210331100132976" style="zoom: 67%;" />





CacheManager：

<img src="https://raw.githubusercontent.com/znsfox/PicGo/master/img/20210331110333.png" alt="image-20210331110333236" style="zoom:67%;" />