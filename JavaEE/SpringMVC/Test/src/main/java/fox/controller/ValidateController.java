package fox.controller;

import fox.pojo.Transaction;
import fox.validator.TransactionValidator;
import org.springframework.stereotype.Controller;
import org.springframework.validation.DataBinder;
import org.springframework.validation.Errors;
import org.springframework.validation.FieldError;
import org.springframework.web.bind.annotation.InitBinder;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.servlet.ModelAndView;


import javax.validation.Valid;
import java.util.List;

/**
 * @description:
 * @author: fox
 * @date: 2020/10/31 10:36
 */
@Controller
@RequestMapping("/validate")
public class ValidateController {

    @RequestMapping("/annotation")
    public ModelAndView annotationValidate(@Valid Transaction trans, Errors errors) {
        // 是否存在错误
        System.out.println("i am coming");
        if (errors.hasErrors()) {
            // 获取错误信息
            List<FieldError> errorList = errors.getFieldErrors();
            for (FieldError error : errorList) {
                // 打印字段错误信息
                System.err.println("field :" + error.getField() + "\t" + "msg:" + error.getDefaultMessage());
            }
        }
        ModelAndView mv = new ModelAndView();
        mv.setViewName("index");
        return mv;
    }

    @InitBinder
    public void initBinder(DataBinder binder) {
        binder.setValidator(new TransactionValidator());
    }

    @RequestMapping("/validator")
    public ModelAndView validator(@Valid Transaction transaction, Errors errors) {
        // 是否存在错误
        System.out.println("i am coming too");
        if (errors.hasErrors()) {
            // 获取错误信息
            List<FieldError> errorList = errors.getFieldErrors();
            for (FieldError error : errorList) {
                // 打印字段错误信息
                System.err.println("filed :" + error.getField() + "\t" + "msg:" + error.getDefaultMessage());
            }
        }
        ModelAndView mv = new ModelAndView();
        mv.setViewName("index");
        return mv;
    }
}
