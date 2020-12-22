package com.example.demo.controller;

import com.example.demo.model.User;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.servlet.ModelAndView;

/**
 * @FileName: MVCDemoController
 * @author: qianBaoLi
 * @date: 2020/11/9 20:03
 * @Description: null
 */
@Controller
public class MVCDemoController {
    @GetMapping("mvcdemo")
    public ModelAndView hello() {
        User user = new User();
        user.setName("zhonghua");
        user.setAge(32);
        ModelAndView modelAndView = new ModelAndView("mvcdemo");
        modelAndView.addObject("user", user);
        return modelAndView;
    }
}
