package fox.controller;

import fox.pojo.Role;
import fox.pojo.RoleParams;
import fox.service.RoleService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.servlet.ModelAndView;
import org.springframework.web.servlet.view.json.MappingJackson2JsonView;

import java.util.List;

/**
 * @description:
 * @author: fox
 * @date: 2020/10/29 14:40
 */
@RequestMapping("/params")
@Controller
public class ParamsController {
    @Autowired
    RoleService roleService = null;
    //{id}代表接收一个参数
    @RequestMapping("/getRole/{id}")
    //注解@PathVariable表示从URL的请求地址中获取参数
    public ModelAndView pathVariable(@PathVariable("id") Long id)  {
        Role role = roleService.getRole(id);
        ModelAndView mv = new ModelAndView();
        //绑定数据模型
        mv.addObject(role);
        //设置为JSON视图
        mv.setView(new MappingJackson2JsonView());
        return mv;
    }

    @RequestMapping("/findRoles")
    public ModelAndView findRoles(@RequestBody RoleParams roleParams) {
        List<Role> roleList = roleService.findRoles(roleParams);
        ModelAndView mv = new ModelAndView();
        //绑定模型
        mv.addObject(roleList);
        //设置为JSON视图
        mv.setView(new MappingJackson2JsonView());
        return mv;
    }

    @RequestMapping("/commonParamsPojo2")
    public ModelAndView  commonParamsPojo2(String roleName, String note) {
        System.out.println("roleName =>" + roleName);
        System.out.println("note =>" + note);
        ModelAndView modelAndView = new ModelAndView();
        modelAndView.setViewName("index");
        return modelAndView;
    }

}
