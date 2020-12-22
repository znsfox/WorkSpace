package com.example.demo.controller;

import com.example.demo.entity.User;
import org.springframework.stereotype.Controller;
import org.springframework.validation.BindingResult;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.servlet.mvc.support.RedirectAttributes;

import javax.validation.Valid;

/**
 * @FileName: TestValidator
 * @author: qianBaoLi
 * @date: 2020/11/13 19:29
 * @Description: null
 */
@Controller
public class TestValidator {
    @GetMapping("/test")
    public String showForm(User user) {
        return "form";
    }

    @GetMapping("/results")
    public String results() {
        return "results";
    }

    @PostMapping("/test")
    public String validateForm(@Valid User user, BindingResult bindingResult, RedirectAttributes attributes) {
        if(bindingResult.hasErrors()) {
            return "form";
        }
        attributes.addFlashAttribute("user",user);
        return "redirect:/results";
    }
}
