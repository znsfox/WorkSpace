package controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.servlet.ModelAndView;
import pojo.Role;
import service.RoleService;

/**
 * @description:
 * @author: fox
 * @date: 2020/10/15 10:32
 */
@Controller
@RequestMapping("/role")
public class RoleController {
    RoleService roleService = null;
    @Autowired
    public void setRoleService(RoleService roleService) {
        this.roleService = roleService;
    }

    @RequestMapping(value = "/getRole",method = RequestMethod.GET)
    public ModelAndView getRole(@RequestParam("id") Long id)
    {
        Role role = roleService.getRole(id);
        ModelAndView modelAndView = new ModelAndView();
        modelAndView.setViewName("roleDetails");
        modelAndView.addObject("role",role);
        return modelAndView;
    }

}
