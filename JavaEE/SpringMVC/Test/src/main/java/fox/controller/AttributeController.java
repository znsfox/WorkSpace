package fox.controller;

import fox.pojo.Role;
import fox.service.RoleService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestAttribute;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.SessionAttributes;
import org.springframework.web.servlet.ModelAndView;
import org.springframework.web.servlet.view.json.MappingJackson2JsonView;

/**
 * @description:
 * @author: fox
 * @date: 2020/10/30 15:50
 */
@Controller
@RequestMapping("/attribute")
@SessionAttributes(names = {"id"},types = {Role.class})
//可以配置数据模型的名称和类型，两者取或关系
public class AttributeController {

    @Autowired
    private RoleService roleService = null;
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

    @RequestMapping("/requestAttribute")
    public ModelAndView reqAttr(@RequestAttribute("id") Long id) {
        ModelAndView mv = new ModelAndView();
        Role role = roleService.getRole(id);
        mv.addObject("role", role);
        mv.setView(new MappingJackson2JsonView());
        return mv;
    }

    @RequestMapping("/sessionAttributes/{id}")
    public ModelAndView sessionAttributes(@PathVariable("id") Long id) {
        ModelAndView modelAndView = new ModelAndView();
        Role role = roleService.getRole(id);
        modelAndView.addObject("role",role);
        modelAndView.addObject("id",id);
        modelAndView.setViewName("sessionAttributes");
        return modelAndView;
    }
}
