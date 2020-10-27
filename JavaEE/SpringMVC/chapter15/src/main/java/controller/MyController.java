package controller;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.servlet.ModelAndView;

/**
 * @description:
 * @author: fox
 * @date: 2020/10/15 9:06
 */
@Controller
@RequestMapping("/my")
public class MyController {
    @RequestMapping("/index")
    public ModelAndView index() {
        ModelAndView modelAndView = new ModelAndView();
        modelAndView.setViewName("index");
        return  modelAndView;
    }

    @RequestMapping("/index2")
    public ModelAndView index2(@RequestParam("id") Long id) {
        System.out.println("params[id=" + id );
        ModelAndView modelAndView = new ModelAndView();
        modelAndView.setViewName("index");
        return modelAndView;
    }
}
