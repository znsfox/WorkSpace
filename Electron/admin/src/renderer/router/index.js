import Vue from 'vue'
import Router from 'vue-router'

Vue.use(Router)

import Main from '@/pages/Main'
import Dashboard from '@/pages/Dashboard'
import Member from '@/pages/Member'


/*
export default new Router({
  routes: [
    {
      path: '/',
      name: 'landing-page',
      component: require('@/components/LandingPage').default
    },
    {
      path: '*',
      redirect: '/'
    }
  ]
})
*/

let routes = [ {
    path: '/',
    component:Main,
    hidden: true,
    children: [{
        path:'/',
        component:Dashboard,
        name:'首页'
    }]
}]

routes.push({
    path: '/member',
    name: '会员管理',
    component: Main,
    iconCls: 'fa fa-user-circle-o',
    children: [{
        path: '/member/data',
        component: Member,
        name: '会员信息管理'
    }]
})

const router =  new Router({
    routes: routes
})

export default router