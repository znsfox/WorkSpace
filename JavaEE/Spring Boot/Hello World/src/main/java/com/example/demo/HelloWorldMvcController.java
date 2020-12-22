package com.example.demo;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;

/**
 * @FileName: HelloWorldMvcController
 * @author: qianBaoLi
 * @date: 2020/11/9 19:04
 * @Description: how to use mvc controller
 */
@Controller
public class HelloWorldMvcController {
    @RequestMapping("/helloworld")
    public String helloWorld(Model model) throws Exception
    {
        model.addAttribute("mav","Hello,Spring Boot!I am the structure of MVC");
        return "example/hello";
    }
}
