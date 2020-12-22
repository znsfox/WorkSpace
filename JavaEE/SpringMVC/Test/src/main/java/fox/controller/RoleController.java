package fox.controller;

import com.mysql.cj.x.protobuf.MysqlxCrud;
import fox.pojo.Role;
import fox.service.RoleService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.servlet.ModelAndView;
import org.springframework.web.servlet.mvc.support.RedirectAttributes;
import org.springframework.web.servlet.view.json.MappingJackson2JsonView;

/**
 * @description:
 * @author: fox
 * @date: 2020/10/30 14:06
 */
@Controller
@RequestMapping("/role")
public class RoleController {

    @Autowired
    private RoleService roleService = null;

    @RequestMapping("/showRoleJsonInfo")
    public ModelAndView showRoleJsonInfo(Long id, String roleName, String note)
    {
        ModelAndView modelAndView = new ModelAndView();
        modelAndView.setView(new MappingJackson2JsonView());
        System.out.println("roleName =>" + roleName);
        System.out.println("note =>" + note);
        modelAndView.addObject("id", id);
        modelAndView.addObject("roleName", roleName);
        modelAndView.addObject("note", note);
        return modelAndView;
    }

    @RequestMapping("/addRole")
    public String addRole(Model model, String roleName, String note) {
        Role role = new Role();
        role.setRoleName(roleName);
        role.setNote(note);
        roleService.insertRole(role);
        model.addAttribute("roleName",roleName);
        model.addAttribute("note",note);
        model.addAttribute("id",role.getId());
        return "redirect:./showRoleJsonInfo.do";
    }

    @RequestMapping("/addRole2")
    public ModelAndView addRole2(ModelAndView mv, String roleName, String note) {
        Role role = new Role();
        role.setRoleName(roleName);
        role.setNote(note);
        roleService.insertRole(role);
        mv.addObject("roleName",roleName);
        mv.addObject("note",note);
        mv.addObject("id",role.getId());
         mv.setViewName("redirect:./showRoleJsonInfo.do");
         return mv;
    }

    @RequestMapping("/showRoleJsonInfo2")
    public ModelAndView showRoleJsonInfo2(Role role)
    {
        ModelAndView modelAndView = new ModelAndView();
        modelAndView.setView(new MappingJackson2JsonView());
        modelAndView.addObject("role",role);
        return modelAndView;
    }

    @RequestMapping("/addRole3")
    public String addRole3(RedirectAttributes ra, Role role) {
        roleService.insertRole(role);
        ra.addFlashAttribute("role",role);
        return "redirect:./showRoleJsonInfo2.do";
    }


}
