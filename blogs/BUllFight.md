# Node.js

### process.env

- 属性会返回包含用户环境的对象

env // 一定执行

.env.development // 开发环境执行

.env.production // 生产环境执行



# Vue

this.$router.push('xxx')



created() 生命周期函数 



### 为什么`appName`要以`$`开头？

`$`是在Vue所有实例中都可用的property的一个简单约定。这样做会避免和以被定义的数据、方法、计算属性产生冲突。

我们通过`$`为实例property设置作用域来避免这种事情发生。



```vue
<template>
  <div class="login_container">
    <div class="login_box">
<!--      头像区域-->
      <div class="avatar_box">
        <img src="../assets/bull.png" alt="头像">
      </div>
<!--     登陆表单区域 -->
      <el-form   ref="loginFormRef" :model="loginForm" :rules="loginFormRules" label-width="0px" class="login_form">
<!--        username-->
        <el-form-item prop="username">
          <el-input v-model="loginForm.username" prefix-icon="iconfont icon-user"></el-input>
        </el-form-item>
        <el-form-item prop="password">
          <el-input v-model="loginForm.password" type="password" prefix-icon="iconfont icon-3702mima"></el-input>
        </el-form-item>
        <el-form-item>
          <el-button type="primary" @click="login">登陆</el-button>
          <el-button type="info" @click="resetLoginFrom">重置</el-button>
        </el-form-item>
        </el-form>
    </div>
  </div>
</template>

<script>
import PrismaClient from '@prisma/client'
const prisma = new PrismaClient()

export default {
  name: 'Login',
  data () {
    return {
      // 这是登陆表单的数据绑定对象
      loginForm: {
        username: '',
        password: ''
      },
      // 这是登陆表单的验证规则
      loginFormRules: {
        username: [
          { required: true, message: '请输入用户名', trigger: 'blur' },
          { min: 3, max: 10, message: '长度在 3 到 10 个字符', trigger: 'blur' }
        ],
        password: [
          { required: true, message: '请输入密码', trigger: 'blur' },
          { min: 6, max: 15, message: '长度在 6 到 15 个字符', trigger: 'blur' }
        ]
      }
    }
  },
  methods: {
    login () {
      this.$refs.loginFormRef.validate(async valid => {
        /* if (!valid) { return }
        const { data: res } = await this.$http.post('login', this.loginForm)
        if (res.meta.status !== 200) return this.$message.error('登陆失败')
        this.$message.success('登陆成功')
        // 将登陆后的token保存到客户端的SessionStorage中
        // 项目中出现了其他的API接口，必须在登陆之后才能再次访问
        // token只应在当前网站打开生效，所以将token保存在session
        // 通过编程式导航跳转到后台主页。
        window.sessionStorage.setItem('token', res.data.token) */
        const result = prisma.user.findUnique({
          where: {
            login: {
              name: this.loginForm.username,
              password: this.loginForm.password
            }
          }
        })
        if (!result) return this.$message.error('登陆失败')
        alert('success')
        await this.$router.push('/home')
        console.log(result)
      })
    },
    // 点击重置按钮，重置登陆表彰
    resetLoginFrom () {
      console.log(this)
      this.$refs.loginFormRef.resetFields()
    }
  }
}
</script>

<style lang="less" scoped>
// scoped vue的指令，只在当前组件生效 */
.login_container {
  background-image: url("../assets/bg.png");
  height: 100%;
}
.login_box {
  width: 450px;
  height: 360px;
  background:linear-gradient(rgba(0,0,0,0),rgba(0,0,0,1));
  border-radius: 3px;
  position: absolute;
  left: 50%;
  top: 50%;
  -webkit-transform: translate(-50%, -50%);

  .avatar_box {
    width: 130px;
    height: 130px;
    border: 1px solid #eee;
    border-radius: 50%;
    padding: 10px;
    box-shadow: 0 0 10px #ddd;
    position: absolute;
    left: 50%;
    transform: translate(-50%, -50%);
    background-color: #fff;
    img {
      width: 100%;
      height: 100%;
      border-radius: 50%;
      background-color: #eee;
    }
  }
}
.login_form {
  position: absolute;
  bottom: 60px;
  width: 100%;
  padding: 0 20px;
  box-sizing: border-box;
}
.btns {
  display: flex;
  justify-content: center;
}
.info {
  font-size: 13px;
  margin: 10px 15px;
}
</style>

```







# stylus

rgb() 取色







npm i css-loader -D

npm install vue-loader vue-template-compiler -D

npm i -D file-loader url-loader

npm i style-loader -D

npm i stylus stylus-loader -D

npm install html-webpack-plugin -D

npm install clean-webpack-plugin -D





yarn add -D eslint eslint-plugin-vue







### Vue_Shop

vue add vue-cli-plugin-element 

vue add vue-cli-plugin-axios





git status

git checkout -b  login

vue add vue-cli-plugin-electron-build





npm i less  less-loader -D



scope不影响其他的组件，只美化自己所在的组件 



# JS

### asnc和await:

async声明一个function是异步的，而await等待一个异步方法执行完成。

async返回的是一个Promise对象。

`promise`对象用于表示一个迅步操作的最终完成。

https://segmentfault.com/a/1190000007535316









项目中的坑：

```
import axios from 'axios'
```



ElementUi中的Message需要进行全局挂载





[electron下使用axios网络请求错误的问题](http://www.okadwin.com/?post=163)

